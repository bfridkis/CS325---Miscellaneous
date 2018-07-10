/***************************************************************
** Program name: stoogesort.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 4/11/2018
** Description: Program to sort arrays of integers in file
                'data.txt'. Outputs values in ascending sorted
                order to file stooge.out. Uses stooge sort
				algorithm for sorting, with running time
				O(n^2.7095...).
****************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

/*void stoogeSort(vector<int>& arrayToSort, int low, int high){
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

int main(){
    ifstream dataIn;
    ofstream dataOut;
    dataIn.open("data.txt");
    dataOut.open("stooge.out");
    int numberOfElements = 0, currentValue;
    while(dataIn >> numberOfElements){
        vector<int> arr;
        for(int i = 0; i < numberOfElements; i++){
            dataIn >> currentValue;
            arr.push_back(currentValue);
        }
        stoogeSort(arr, 0, arr.size() - 1);
        for(int i = 0; i < numberOfElements; i++){
            dataOut << arr.at(i) << " ";
        }
        dataOut << "\r\n" << endl;
        numberOfElements = 0;
    }
}*/
