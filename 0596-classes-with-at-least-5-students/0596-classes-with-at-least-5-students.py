import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby(courses['class'],as_index = False)['student'].count()
    return df[df['student']>=5][['class']]