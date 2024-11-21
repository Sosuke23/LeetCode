import pandas as pd

def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    x, y, z, res = [], [], [], []
    for t in range (len(triangle)):
        a, b, c = triangle['x'][t], triangle['y'][t], triangle['z'][t]
        # print(a, b, c)
        p = [a, b, c]
        x.append(a)
        y.append(b)
        z.append(c)
        p.sort()
        if p[0] + p[1] > p[2]:
            res.append('Yes')
        else:
            res.append('No')

    d = {'x' : x, 'y' : y, 'z' : z, 'triangle' : res}
    new_pd = pd.DataFrame.from_dict(d)
    return new_pd

    