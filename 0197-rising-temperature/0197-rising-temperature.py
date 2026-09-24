import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather = weather.sort_values('recordDate')
    weather['prev_date'] = weather['recordDate'].shift(1)
    weather['prev_temp'] = weather['temperature'].shift(1)

    return weather[((weather['prev_date']-weather['recordDate']).dt.days==-1) & (weather['prev_temp']<weather['temperature'])].drop(columns=['recordDate','temperature','prev_date','prev_temp']).rename(columns = {'id':'Id'})