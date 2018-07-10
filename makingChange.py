#################################################################
## Program name: makingChange.py
## Class name: CS325-400
## Author: Ben Fridkis
## Date: 4/19/2018
## Description: Program to provide the minimum number of coins
##				based on a provided set of coin value 
##				denominations and a value to "make change for".
##				Running time of the function minimumChange is
##				theta(n^2). Program reads file "amount.txt"
##				which provides various coin denomination values
##				and a corresponding amount to make change for,
##				and outputs results in file "change.txt".
#################################################################

def minimumChange(V, A):
	singleCoin = False
	C = []
	for denomination in V:
		if denomination == A:
			C.append(1)
			singleCoin = True
		else:
			C.append(0)
	if singleCoin:
		C.append(1)
		return C
	CA = [[0 for y in range(len(V) + 1)] for x in range(A + 1)]
			
	for i in range(1, A + 1):
		if i in V:
			CA[i][V.index(i)] = 1
			CA[i][len(V)] = 1			#The last array element holds the coin count
		else:	
			minArray = []
			for j in range(1, int(i/2) + 1):
				currentArray = [x + y for x, y in zip(CA[i - j], CA[i - (i - j)])]	
				if j == 1:
					minArray = currentArray
				else:
					if currentArray[len(V):] < minArray[len(V):]:
						minArray = currentArray		
			for k in range(len(V) + 1):		
				CA[i][k] = minArray[k]	 
	
	return CA[A]

try:
	fhand = open("amount.txt")
except:
	"Unable to open amount.txt. Goodbye."

fout = open('change.txt', 'w')	
	
lineNumber = 1
V = []
C = []
for line in fhand:
	if lineNumber % 2 == 1:
		V = list(map(int, line.split()))	
		lineNumber += 1
	else:
		A = int(line.strip("\n"))
		C = minimumChange(V, A)
		fout.write(' '.join(str(value) for value in V) + "\r\n")
		fout.write(str(A)+"\r\n")
		fout.write(' '.join(str(coinsPerDenomination) for coinsPerDenomination in C[:len(C)-1]) + "\r\n")
		fout.write(str(C[len(C)-1])+"\r\n")
		lineNumber += 1

fout.close()		