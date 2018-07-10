/***************************************************************
** Program name: mergesort_runningtime.cpp
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

void merge(vector<int>& arrayToSort, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for(int i = 0; i < n1; i++){
        leftArr[i] = arrayToSort.at(i + low);
    }
    for(int i = 0; i < n2; i++){
        rightArr[i] = arrayToSort.at(i + 1 + mid);
    }
    int i = low, j = 0, k = 0;
    while(j < n1 && k < n2){
        if(leftArr[j] <= rightArr[k]){
            arrayToSort[i] = leftArr[j];
            j++;
        }
        else{
            arrayToSort[i] = rightArr[k];
            k++;
        }
        i++;
    }
    while(j < n1){
        arrayToSort[i] = leftArr[j];
        j++;
        i++;
    }
    while(k < n2){
        arrayToSort[i] = rightArr[k];
        k++;
        i++;
    }
}

void mergeSort(vector<int>& arrayToSort, int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(arrayToSort, low, mid);
        mergeSort(arrayToSort, mid + 1, high);
        merge(arrayToSort, low, mid, high);
    }
}

//Loads vectors of various sizes with integers in descending
//order, starting at the integer equivalent to the size of
//the vector.
void loadVectorWorstCase(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(vSize - i);
    }
}

//Loads vectors of various sizes with integers in ascending (sorted)
//order, starting at 0.
void loadVectorBestCase(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(i);
    }
}

//Sorts using insertionSort and outputs elapsed time for
//sorting to the console.
void timeMergeSort(vector<int>& vectorToSort, int datapoint){
    clock_t begin = clock();

    mergeSort(vectorToSort, 0, vectorToSort.size() - 1);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << datapoint << ": " << elapsed_secs << endl;
}

int main(){

    vector<int> vectors[10];
    cout << "Worst Case Execution Times (Merge Sort):" << endl;
    for(int i = 0, vSize = 10000; i < 10; i++){
        loadVectorWorstCase(vectors[i], vSize);
        timeMergeSort(vectors[i], i + 1);
        vectors[i].clear();
        vSize += 10000;
    }

    cout << endl << "Best Case Execution Times (Merge Sort):" << endl;
    for(int i = 0, vSize = 10000; i < 10; i++){
        loadVectorBestCase(vectors[i], vSize);
        /*for(int j = 0; j < 10; j++){
            cout << vectors[i].at(j) << " ";
        }
        cout << endl;*/
        timeMergeSort(vectors[i], i + 1);
        /*for(int j = 0; j < 10; j++){
            cout << vectors[i].at(j) << " ";
        }
        cout << endl;*/
        vSize += 10000;
    }
}

