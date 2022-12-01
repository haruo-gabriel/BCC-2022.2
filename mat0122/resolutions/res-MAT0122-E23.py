#------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Gabriel Haruo Hanai Takeuchi
# Numero USP: 13671636
# Tarefa: E23
# Data: 21/09/2022
# 
# Baseado em ... (breve e se aplicável)
# 
# DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS 
# PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO  
# PELO PROFESSOR OU COPIADAS DO LIVRO OU DO MATERIAL DIDÁTICO DE MAT0122, 
# FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS 
# AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
# DE CÓPIAS DESTA PROGRAMA.
#------------------------------------------------------------------------------


from mat import Mat
from mat import matrix_matrix_mul

'''
Justifying my answer:

According to PNK (section 4.11.2 - page 232), 

    'the adjacency matrix A itself encodes the number of one-step walks'
    'Row i of A is a vector u such that u[k] is the number of one-step walks
    from i to k. Column j of A is a vector v such that v[k] is the number of
    one-step walks from k to j. Therefore the dot-product of row i with column j
    is the number of two-step walks from i to j. By the dot-product definition
    of matrix-matrix multiplication, therefore, the product AA encodes the number
    of two-step walks.'

    'A three-step walk from i to j consists of a two-step walk from i to some
    node k, followed by a one-step walk from k to j.'
    'We already know that AA gives the number of two-step walks. Again using the
    dot-product definition of matrix-matrix multiplication, the product (AA)A gives
    the number of three-step walks'

By taking advantage of this idea,
    a n-step walk from i to j is a (n-1)-step walk from i to j followed by a 1-step walk
    from i to j.

    But a (n-1)-step walk from i to j is a (n-2)-step walk from i to j followed by a
    1-step walk from i to j.

    But a (n-2)-step walk from i to j is a (n-3)-step walk from i to j followed by a
    1-step walk from i to j.
    
    And so on...

Recursively, it is possible to infer that the matrix for n-step walks can be
generated through multiplying the 1-step walk matrix by itself n-1 times.
'''



# E23 (i)
print('E23 (i)')

# Routine to print the 1-step walks adjacency matrix
print('Suppose A is the adjacency matrix from the PNK section 4.11.2.\n')
A = Mat(({1,2,3,4},{1,2,3,4}), {(1,2):1, (1,4):1, (2,1):1, (2,3):2, (2,4):1, (3,2):2, (4,1):1, (4,2):1})
print('Adjacency matrix A:')
print(A)
print('\n')

# for loop to generate the 32-step walks matrix
Aaux = A
for i in range(31):
    Aaux = Aaux * A

    # Conditional statement to print the 4-step walks
    if i == 2:
        print('Matrix A*A*A*A:')
        print(Aaux)
        print('There are  {}  4-step walks from node 3 to node 2.\n\n'.format(Aaux[3,2]))

# Routine to print the generated matrix
print('Matrix A*A*. ... *A*A (32 A\'s):')
print(Aaux)
print('There are  {}  32-step walks from node 3 to node 2.'.format(Aaux[3,2]))



print('\n\n------------------------------------------------------------------------------\n\n')



# E23 (ii)
print('E23 (ii)')

# Routine to print the 1-step walks adjacency matrix
print('Suppose B is the adjacency matrix from the wikipedia graph.\n')
B = Mat(({1,2,3,4,5,6},{1,2,3,4,5,6}), {(1,2):1, (2,1):1, (1,5):1, (5,1):1, (2,3):1, (3,2):1, (2,5):1, (5,2):1, (5,4):1, (4,5):1, (3,4):1, (4,3):1, (4,6):1, (6,4):1})
print('Adjacency matrix B:')
print(B)
print('\n')

# for loop to generate the 32-step walks matrix
Baux = B
for i in range(31):
    Baux = Baux * B

# Routine to print the generated matrix
print('Matrix B*B*. ... *B*B (32 A\'s):')
print(Baux)
print('There are  {}  32-step walks from node 1 to node 6.'.format(Baux[1,6]))
