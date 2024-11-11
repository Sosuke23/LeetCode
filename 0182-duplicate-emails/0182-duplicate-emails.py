import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    res = []
    email = []
    for x in person['email']:
        if x == 'nan' or x == 'NaN':
            continue
        if email.count(x):
            if res.count(x) == 0:
                res.append(x)

        else:
            email.append(x)
    
    d = {'Email' : res}
    new_pd = pd.DataFrame.from_dict(d)
    return new_pd
    