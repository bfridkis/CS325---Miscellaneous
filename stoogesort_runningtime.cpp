/***************************************************************
** Program name: stoogesort_runningtime.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 4/12/2018
** Description: Program to sort arrays of integers of various
                sizes and output running times for each.
                Uses stooge sort algorithm for sorting, with
                running time O(n^2.7095...).
****************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;

void stoogeSort(vector<int>& arrayToSort, int low, int high){
    if(high - low + 1 == 2 && arrayToSort[low] > arrayToSort[high]){
        int temp = arrayToSort[high];
        arrayToSort[high] = arrayToSort[low];
        arrayToSort[low] = temp;
    }
    else if(high - low + 1 > 2){
        float calc = ((high-low+1)*2)/3.0;
        int m = static_cast<int>(ceil(calc));
        stoogeSort(arrayToSort, low, m - 1 + low);
        stoogeSort(arrayToSort, high + 1 - m, high);
        stoogeSort(arrayToSort, low, m - 1 + low);
    }
}

//Loads vectors of various sizes with random integers
//in range of 1 to 1000.
void loadVector(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(1 + rand() % 1000);
    }
}

//Sorts using stoogeSort and outputs elapsed time for
//sorting to the console.
void timeStoogeSort(vector<int>& vectorToSort, int datapoint){
    clock_t begin = clock();

    stoogeSort(vectorToSort, 0, vectorToSort.size() - 1);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << datapoint << ": " << elapsed_secs << endl;
}

int main(){
    //Use the time function to
	//get a "seed" value for srand
	unsigned seed = time(0);
	srand(seed);

    vector<int> vectors[10];

    for(int i = 0, vSize = 1000; i < 10; i++){
        loadVector(vectors[i], vSize);
        timeStoogeSort(vectors[i], i + 1);
        vSize += 1000;
    }
}

