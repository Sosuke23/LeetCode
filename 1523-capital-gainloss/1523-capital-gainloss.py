import pandas as pd

def capital_gainloss(stocks: pd.DataFrame) -> pd.DataFrame:
    table = dict({})
    # print(stocks['operation'][0])
    for i in range(len(stocks)):
        if stocks['operation'][i] == 'Buy':
            if stocks['stock_name'][i] in table:
                table[stocks['stock_name'][i]] -= stocks['price'][i]
            else:
                table[stocks['stock_name'][i]] = -stocks['price'][i]
                
        else:
            if stocks['stock_name'][i] in table:
                table[stocks['stock_name'][i]] += stocks['price'][i]
            else:
                table[stocks['stock_name'][i]] = stocks['price'][i]

    new_df = dict({})
    stock_name = []
    capital_gain_loss = []
    for x in table.keys():
        stock_name.append(x)
        capital_gain_loss.append(table[x])

    new_df = {
        'stock_name' : stock_name,
        'capital_gain_loss' : capital_gain_loss
    }        

    res = pd.DataFrame.from_dict(new_df)
    return res


            
    