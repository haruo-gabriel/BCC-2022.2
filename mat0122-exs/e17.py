from GF2 import one
from vec import Vec
from vecutil import list2vec


gf2 = [0, one]

def generate(a):
    print('a:', a)
    b = []
    for x in range(len(a)):
        print('a[x]:', a[x])
        for y in range(len(gf2)):
            print('gf2[y]:', gf2[y])
            b.append(list(a[x].append(gf2[y])))

    print('b:',b)

    return b


D = {'a', 'b', 'c'}

L = [Vec(D, {'a':0, 'b':one, 'c':one}), Vec(D, {'a':one, 'b':0, 'c':one})]

combinations = [ [[0], [one]] ]

for i in range(2):
    support = list(combinations[i])
    print('support:', support)

    lista = generate(support)
    print('lista:', lista)

    combinations.append(lista)
    print('combinations:', combinations)

    lista.clear()
    support.clear()

#print(combinations)





