#################################################################
## Program name: makingChange_RunningTimes_TimeAsAFunctionOfA.py
## Class name: CS325-400
## Author: Ben Fridkis
## Date: 4/19/2018
## Description: Program to time minimumChange for various sizes
##				of array parameter "V".
#################################################################

import time
import random

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

for i in range(1, 11):
	A = 3000
	V = [1] + random.sample(range(2, A+1),i*10-1)
	start_time = time.time()
	minimumChange(V, A)
	end_time = time.time()
	run_time = end_time - start_time
	print(str(A) + ": " + str(run_time))

print("\n\n----Done----\n\n")