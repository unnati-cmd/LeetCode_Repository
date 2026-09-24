import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    result = pd.merge(customers,orders,left_on = 'id',right_on ='customerId',how='left')
    return result[result['id_y'].isnull()].drop(columns=['id_x','id_y','customerId']).rename(columns={'name':'Customers'})