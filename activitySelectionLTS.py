########################################################################
## Program name: activitySelectionLTS.py
## Class name: CS325-400
## Author: Ben Fridkis
## Date: 4/27/2018
## Description: Program to return a maximum size subset of compatible 
##				"activities" for each of multiple sets of activities
##				when an argument containing said activity sets is 
##				passed to the "activitySelectionLTS" function. The 
##				results are outputted to the terminal window.
########################################################################

def startTime(activity):
	return activity[1]

def activitySelectionLTS(S):			#Parameter S is an array of tuples, 
										#of the format (start_time, finish_time, activity#)
	S.sort(key=startTime, reverse=True)									
	A = [S[0]]									
	for m in range(2, len(S)):
		if S[m][2] <= A[len(A)-1][1]:
			A.append(S[m])
	return A

try:
	fhand = open("act.txt")
except:
	"Unable to open act.txt. Goodbye."

activityCountLineNumber = 0
activityCount = 0
newSet = True
S = []
for i, line in enumerate(fhand):									#This for loop establishes S as an array of arrays,
	if i == activityCountLineNumber:								#where each element array is a list of tuples of the form
		activityCountLineNumber += int(line.split()[0]) + 1			#(activity number, start_time, finish_time). 
		newSet = True
	else:
		if	newSet:
			S.append([])
		activityList = list(map(int, line.split()))
		S[len(S)-1].append(tuple(activityList))
		newSet = False
for i, set in enumerate(S, start=1):								#This for loop prints the results of running activitySelectionLTS
	A = activitySelectionLTS(set)									#on each set of activities.
	A.sort()
	print("Set " + str(i))
	print("Number of activities selected = " + str(len(A)))
	print("Activities: " + " ".join(str(activity[0]) for activity in A))