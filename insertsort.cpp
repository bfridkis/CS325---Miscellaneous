/***************************************************************
** Program name: insertsort.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 4/6/2018
** Description: Program to sort arrays of integers in file
                'data.txt'. Outputs values in ascending sorted
                order to file insert.out. Uses insertion sort
				algorithm for sorting, with running time O(n^2).
****************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

void insertionSort(vector<int>& arrayToSort){
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

int main(){
    ifstream dataIn;
    ofstream dataOut;
    dataIn.open("data.txt");
    dataOut.open("insert.out");
    int numberOfElements = 0, currentValue;
    while(dataIn >> numberOfElements){
        vector<int> arr;
        for(int i = 0; i < numberOfElements; i++){
            dataIn >> currentValue;
            arr.push_back(currentValue);
        }
        insertionSort(arr);
        for(int i = 0; i < numberOfElements; i++){
            dataOut << arr.at(i) << " ";
        }
        dataOut << "\r\n" << endl;
        numberOfElements = 0;
    }
}
