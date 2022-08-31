#------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Gabriel Haruo Hanai Takeuchi
# Numero USP: 13671636
# Tarefa: E6 (Problema 1.5.1 de PNK)
# Data: 30/08/2022
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

from GF2 import one

numbers = [0, one] 
binaries = [(a, b, c, d, e) for a in numbers for b in numbers for c in numbers for d in numbers for e in numbers]
binaries26 = binaries[:27]

alphabet = [chr(ord('A')+x) for x in range(26)]
alphabet.append(' ')

# We can make a dictionary for the function b2a: binaries -> alphabet,
# since both functions b2d: binaries -> decimals and d2a: decimals -> alphabet are bijective.
b2a = {x:y for (x, y) in zip(binaries26, alphabet)}


cyphertext = [(one, 0, one, 0, one),  (0, 0, one, 0, 0), (one, 0, one, 0, one), (0, one, 0, one, one),(one, one, 0, 0, one), (0, 0, 0, one, one), (0, one, 0, one, one), (one, 0, one, 0, one), (0, 0, one, 0, 0), (one, one, 0, 0, one), (one, one, 0, one, 0)]


# Iterating through all
ptxt_bin_lists = []
ptxt_bin_tuples = []
ptxt = []

for bin in binaries:
    # Here, we use a probable key to decodify every character of the cyphertext
    ptxt_bin_lists.clear()
    for char in cyphertext:
        ptxt_bin_lists.append( [x + y for (x, y) in zip(bin, char)] )
    
    # Here, we already have a decodified word in binary, but every character is a list. We need every character to be a tuple
    # so we can use it as a key for our dictionary b2a. 
    ptxt_bin_tuples.clear()
    for char in ptxt_bin_lists:
        ptxt_bin_tuples.append(tuple(char))

    # Now, we have the decodified text in tuples (and still in binary). We need to turn it into a real word.
    ptxt.clear()
    for char in ptxt_bin_tuples:
        if (char in b2a.keys()):
            ptxt.append(b2a[char])
        else:
            break
    print("Key: {} Word: {}\n".format(bin, ptxt))

# The only output that makes sense is:
# Key: (one, 0, 0, 0, one) Word: ['E', 'V', 'E', ' ', 'I', 'S', ' ', 'E', 'V', 'I', 'L']

