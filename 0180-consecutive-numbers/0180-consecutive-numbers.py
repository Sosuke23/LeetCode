import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    cnt = 1
    res = []
    if len(logs['num']) > 0:
        prev = logs['num'][0]
        for i in range(1, len(logs['num'])):
            if prev == logs['num'][i]:
                cnt += 1
            else:
                if cnt >= 3:
                    if res.count(prev) == 0:
                        res.append(prev)
                cnt = 1
                prev = logs['num'][i]

        if cnt >= 3:
            if res.count(prev) == 0:
                res.append(prev)
    
    d = {'ConsecutiveNums': res}
    res_pd = pd.DataFrame.from_dict(d)
    return res_pd

    