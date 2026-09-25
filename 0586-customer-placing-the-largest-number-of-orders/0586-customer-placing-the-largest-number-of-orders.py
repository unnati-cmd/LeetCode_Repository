import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    df = orders.groupby(orders['customer_number'],as_index=False)['order_number'].count()
    return df.sort_values(by='order_number').tail(1).drop(columns=['order_number'])