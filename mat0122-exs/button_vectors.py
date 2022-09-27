from GF2 import one
from matutil import coldict2mat
from vec import Vec
from mat import Mat
from GF2_span import GF2_span
from solver import solve

def button_vectors(n):
    D = {(i,j) for i in range(n) for j in range(n)}
    vecdict={(i,j) : Vec(D, dict([((x,j),one) for x in range(max(i-1,0), min(i+2,n))] + [((i,y),one) for y in range(max(j-1,0), min(j+2,n))])) for (i,j) in D}
    return vecdict

B = coldict2mat(button_vectors(2))
print(B)

L = [Vec(B.D[0], {x:one}) for x in B.D[0]]
print(L)

print(GF2_span(B.D[0], L))