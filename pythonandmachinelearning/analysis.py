'''import csv
import pandas as pd
import csv
results = []
with open("/Users/prakalp/Downloads/results.csv") as csvfile:
    csvreader = csv.DictReader(csvfile)
    for row in csvreader:
        # print(row)
        results.append(row)
final_dict = {}
for (i, result) in enumerate(results):
    if result['Metric-name']:
        if result['Metric-name'] in final_dict:
            if result['Exp_names'] in final_dict[result['Metric-name']]:
                final_dict[result['Metric-name']][result['Exp_names']+result['Iteration']].append({
                    #'Metric-name': result['Metric-name'],
                     result['avg'],
                     result['min'],
                    result['max'],
                     result['median']
                })
            else:
                final_dict[result['Metric-name']][result['Exp_names']+result['Iteration']] =[
                    #'Metric-name': result['Metric-name'],
                     result['avg'],
                     result['min'],
                     result['max'],
                     result['median']
                ]
        else:
            final_dict[result['Metric-name']] = {
                result['Exp_names']+result['Iteration']: [
                   # 'Metric-name': result['Metric-name'],
                     result['avg'],
                     result['min'],
                     result['max'],
                     result['median']
]
            }
new = pd.DataFrame.from_dict(final_dict)
print(new)
new.to_csv('mldata.csv')
file=open('mldata.csv')
csvreader = csv.reader(file)'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('/Users/prakalp/Downloads/results.csv')


def normalize_columns(df):
    df.columns = [c.lower() for c in df.columns]
    return df


def keep_relevant_cols(df, metric_cols):
    keep_cols = ['exp_names', 'iteration', 'metric-name'] + metric_cols

    df2 = df[keep_cols].copy()
    return df2


def check_equality(df, df2, should_assert=False):
    for c in set(df.columns).intersection(df2.columns):
        '''print(np.sum(df[c] != df2[c]))
        print(df[df[c] != df2[c]], df2[df[c] != df2[c]])'''
        if should_assert:
            assert (np.sum(df[c] != df2[c]) == 0, print(c))


def check_nans(df):
   ''' print(f'Shape = {df.shape}')
    print(f'Shape after dropping nans: {df.dropna().shape}')'''


def print_null_rows(df):
    return df.iloc[np.where(df.isnull().sum(axis=1))]


if __name__ == '__main__':
    df = normalize_columns(df)
    metric_cols = ['avg', 'min', 'max'] + [c for c in df.columns if c.find('percentile') > -1]

    df2 = keep_relevant_cols(df, metric_cols)

    check_equality(df, df2)

    check_nans(df)
    check_nans(df2)
    df_list = []
    for c in metric_cols:
        df_pivot = pd.pivot_table(df2, index=['exp_names', 'iteration'], columns='metric-name', values=c)
        df_pivot.columns = [f'{k}_{c}' for k in df_pivot.columns]
        df_list.append(df_pivot)
    #df_final = pd.concat(df_list, axis=1).reset_index()
    df_final = pd.concat(df_list, axis=1)
    # different experiments have different number of collected metrics?
    print(df['metric-name'].value_counts())
    print(df_final)
    df_final.to_csv('yy.csv')
def for_other_file(df):
    return df_final


