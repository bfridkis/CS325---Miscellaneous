/***************************************************************
** Program name: insertsort_runningtime.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 4/6/2018
** Description: Program to sort arrays of integers of various
                sizes and output running times for each.
                Uses insertion sort algorithm for sorting, with
                running time O(n^2).
****************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::vector;

/*void insertionSort(vector<int>& arrayToSort){
    for(unsigned i = 1; i < arrayToSort.size(); i++){
        int key = arrayToSort[i];
        int j = i - 1;
        while (j >= 0 && arrayToSort[j] > key){
            arrayToSort[j + 1] = arrayToSort[j];
            j = j - 1;
        }
        arrayToSort[j + 1] = key;
    }
}

//Loads vectors of various sizes with random integers
//in range of 1 to 1000.
void loadVector(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(1 + rand() % 1000);
    }
}

//Sorts using insertionSort and outputs elapsed time for
//sorting to the console.
void timeInsertionSort(vector<int>& vectorToSort, int datapoint){
    clock_t begin = clock();

    insertionSort(vectorToSort);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << datapoint << ": " << elapsed_secs << endl;
}

/*int main(){
    //Use the time function to
	//get a "seed" value for srand
	unsigned seed = time(0);
	srand(seed);

    vector<int> vectors[10];

    for(int i = 0, vSize = 10000; i < 10; i++){
        loadVector(vectors[i], vSize);
        timeInsertionSort(vectors[i], i + 1);
        vSize += 10000;
    }
}*/

