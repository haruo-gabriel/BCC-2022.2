from vec import Vec
from vecutil import list2vec
from triangular import triangular_solve

D = {'A', 'B', 'C', 'D'}

a = Vec(D, {'B': 1, 'D': 5})
b = Vec(D, {'A': -2, 'B': 1, 'C': 4, 'D': .5})
c = Vec(D, {'B': 2})
d = Vec(D, {'A': 2, 'B': 3, 'D':3})

x = triangular_solve([b, d, a, c], ['C', 'A', 'D', 'B'], list2vec([6, -4, 3, 8]))

print(x)