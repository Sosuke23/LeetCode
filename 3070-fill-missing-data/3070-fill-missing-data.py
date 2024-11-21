import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    for i in range(len(products['name'])):
        if pd.isnull(products['quantity'][i]):
            products['quantity'][i] = 0
            
    return products
    