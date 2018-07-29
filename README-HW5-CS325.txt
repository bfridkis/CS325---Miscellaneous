README.TXT - CS325 HW5
AUTHOR: BENJAMIN FRIDKIS

To execute babyFaceOrHeel, perform the following steps:
1.  Copy source files (babyFaceOrHeel.cpp & makefile) to the directory of your choice.

2.  Navigate to this directory (i.e. the directory to which the files were pasted in step 1) 
	in your system's terminal/console.
	
3.  Place a test file (with a name of your choosing) in this same directory.
	(This test file contains a wrestler count followed wrestler names followed a rivalry count followed by rivalries.
	 each count, name, and rivalry is on its own newline, with rivarlies given by two wrestler names seperated by whitespace.)
	
3.  Type the command "make" (without quotes).
	This will compile the program (babyFaceOrHeel).
	
4.  Type the command "./babyFaceOrHeel" (without quotes) followed by the name of the test file. 
		-For example, if test file is named "test.txt", type "./babyFaceOrHeel test.txt" in the command line (without quotes).
	This will execute the program (babyFaceOrHeel) with the specified test file.
	
5. Once finished with program, type the command "make clean" (without quotes)
   to delete the object files and the executable file files generated in the steps above.
   (Ignore any "rm: cannot remove..." errors.)