import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    df = orders.groupby(orders['customer_number'],as_index=False)['order_number'].count()
    maximum = df['order_number'].max()
    return df[df['order_number']==maximum][['customer_number']]