import pandas as pd
import numpy as np

data = pd.read_csv(r'passos_frequencia.csv')
df = pd.DataFrame(data, columns=['Frequencia'])
print(df)
print(df.hist())