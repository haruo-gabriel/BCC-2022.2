from vecutil import zero_vec
from vec import Vec
from GF2 import one

"""
Returns a list of all linear combinations (as lists, too) of size len(D).

Example: if len(D) == 2, then it returns [[0,0], [0,1], [1,0], [1,1]]
"""
def generateCombsLists(turns):
	allScalarCombsLists = [ [[0], [1]] ]

	for i in range(turns - 1):
		allScalarCombsLists.append( appendScalar(allScalarCombsLists[i]) )

	return allScalarCombsLists[-1]

"""
Returns a list of all linear combinations (as lists, too) one size greater
than the linear combinations of scalarCombsList.

Example: if scalarCombsList = [[0,0], [0,1], [1,0], [1,1]] (the size of the combinations` 2),
then it returns [[0,0,0], [0,0,1], [0,1,0], [0,1,1], [1,0,0], [1,0,1], [1,1,0], [1,1,1]] (the
size of the combinations` now 3).
"""
def appendScalar(scalarCombsList):
	gf2 = [0, 1]
	supportList = []

	for i in range(len(scalarCombsList)):
		for j in gf2:
			scalarCombAppended = list(scalarCombsList[i])
			scalarCombAppended.append(j)
			supportList.append(scalarCombAppended)
	
	return supportList

"""
Input: a set D of labels and a list L of vectors over GF (2) with label-set D
Output: the list of all linear combinations of the vectors in L
"""
def GF2_span(D, L):
	if len(L) == 0:
		return [zero_vec(D)]

	else:
		scalarCombs = generateCombsLists(len(L))
		span = []

		for c in scalarCombs:
			addCombs = sum([x*y for (x, y) in zip(c, L)])
			if addCombs not in span:
				span.append(addCombs)
		return span
		

def main():
	# Example input
	D = {'a', 'b', 'c'}
	L = [Vec(D, {'a':0, 'b':one, 'c':one}), Vec(D, {'a':one, 'b':0, 'c':one})]

	print(GF2_span(D,L))

if __name__ == '__main__':
	main()
