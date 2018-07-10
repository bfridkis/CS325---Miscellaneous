/*****************************************************************
** Program name: mergesort.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 4/6/2018
** Description: Program to sort arrays of integers in file
                'data.txt'. Outputs values in ascending sorted
                order to file merge.out. Uses merge sort
				algorithm for sorting, with running time O(nlogn).
******************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using std::endl;
using std::ifstream;
using std::ofstream;
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

int main(){
    ifstream dataIn;
    ofstream dataOut;
    dataIn.open("data.txt");
    dataOut.open("merge.out");
    int numberOfElements = 0, currentValue;
    while(dataIn >> numberOfElements){
        vector<int> arr;
        for(int i = 0; i < numberOfElements; i++){
            dataIn >> currentValue;
            arr.push_back(currentValue);
        }
        mergeSort(arr, 0, arr.size() - 1);
        for(int i = 0; i < numberOfElements; i++){
            dataOut << arr.at(i) << " ";
        }
        dataOut << "\r\n" << endl;
        numberOfElements = 0;
    }
}
