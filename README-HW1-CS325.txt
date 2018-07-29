README.TXT - CS325 HW1
AUTHOR: BENJAMIN FRIDKIS

To execute insertsort and mergesort, perform the following steps:
1.  Copy files (insertsort.cpp, mergesort.cpp, makefile) to the directory of your choice.

2.  Navigate to this directory (i.e. the directory to which the files were pasted in step 1) 
	in your system's terminal/console.
	
3.  Place "data.txt" file in this same directory.
	("data.txt" contains integer data items prefaced by an integer data item count representing 
	integer arrays. Each array is seperated by a newline.)
	
3.  Type the command "make all" (without quotes).
	This will compile the programs (insertsort & mergesort).
	
4.  Type the command "make runall" (without quotes). 
	This will execute the programs (insertsort & mergesort).
	The files "insert.out" and "merge.out" will be generated in the same directory.
	These files contain the sorted arrays from "data.txt".
	
5. Once finished with programs and data, type the command "make clean" (without quotes)
   to delete the object files, executable files, and .out files generated in the steps above.
   (Ignore any "rm: cannot remove..." errors.)
   
**EXTRA CREDIT**
1.  Copy files (insertsort_runningtime_EXTRA-CREDIT.cpp, mergesort_runningtime_EXTRA-CREDIT.cpp, makefile) 
	to the directory of your choice.

2.  Navigate to this directory (i.e. the directory to which the files were pasted in step 1) 
	in your system's terminal/console.
	
3.  Type the command "make extracredit" (without quotes).
	This will compile the programs (insertsort_runningtime_EXTRA-CREDIT & mergesort_runningtime_EXTRA-CREDIT).
	
4.  Type the command "make runextracredit" (without quotes). 
	This will execute the programs (insertsort_runningtime_EXTRA-CREDIT & mergesort_runningtime_EXTRA-CREDIT).
	
5. Once finished with programs, type the command "make clean" (without quotes)
   to delete the object files, executable files, and .out files generated in the steps above.
   (Ignore any "rm: cannot remove..." errors.)