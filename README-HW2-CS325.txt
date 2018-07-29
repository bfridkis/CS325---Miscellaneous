README.TXT - CS325 HW2
AUTHOR: BENJAMIN FRIDKIS

To execute stoogesort, perform the following steps:
1.  Copy files (stoogesort.cpp & makefile) to the directory of your choice.

2.  Navigate to this directory (i.e. the directory to which the files were pasted in step 1) 
	in your system's terminal/console.
	
3.  Place "data.txt" file in this same directory.
	("data.txt" contains integer data items prefaced by an integer data item count representing 
	integer arrays. Each array is seperated by a newline.)
	
3.  Type the command "make" (without quotes).
	This will compile the program (stoogesort).
	
4.  Type the command "make run" (without quotes). 
	This will execute the program (stoogesort).
	The file "stooge.out" will be generated in the same directory.
	This files contain the sorted arrays from "data.txt".
	
5. Once finished with programs and data, type the command "make clean" (without quotes)
   to delete the object files, executable files, and .out files generated in the steps above.
   (Ignore any "rm: cannot remove..." errors.)