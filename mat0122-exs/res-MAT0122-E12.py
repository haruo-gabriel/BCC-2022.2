from vec import Vec

D = {'A', 'B', 'C', 'D'}
a = Vec(D, {'B': 1, 'D': 5})
b = Vec(D, {'A':10, 'B':4, 'C':1})

print(add(a, b).f)