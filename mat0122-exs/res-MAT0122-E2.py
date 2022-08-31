#------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Gabriel Haruo Hanai Takeuchi
# Numero USP: 13671636
# Tarefa: E2 - Problema 0.8.3 de PNK
# Data: 21/08/2022
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

def main():
	A = [(1, 2), (10, 20)]
	B = [(3, 4), (30, 40)]
	print( [ (x+a, y+b) for ((x, y), (a, b)) in list(zip(A, B)) ] )

if __name__ ==  "__main__":
	main()

#Expected output: [(4, 6), (40, 60)]
