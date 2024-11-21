import pandas as pd

def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:
    a, b = set({}), set({})
    for x in employees['employee_id']:
        a.add(x)

    for x in salaries['employee_id']:
        b.add(x)

    c = a ^ b
    arr = []
    for x in c:
        arr.append(x)
    
    d = {'employee_id' : arr}
    new_pd = pd.DataFrame.from_dict(d)
    return new_pd