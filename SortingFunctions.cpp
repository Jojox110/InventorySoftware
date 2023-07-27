#include"SortingFunctions.h"
#include<iostream>
#include<vector>
#include<QString>
#include<QDebug>

void swap(double *a, double *b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(std::vector<double>& array, int left, int pivot){
    if(left < pivot){
        int new_pivot = partition(array, left, pivot);

        quickSort(array, left, new_pivot - 1);
        quickSort(array, new_pivot + 1, pivot);
    }
}

int partition(std::vector<double>& array, int left, int pivot){
    int low = left - 1;
    int high = pivot - 1;

    for(int j = left; j <= high; j++){
        if(array[j] <= array[pivot]){
            low++;
            swap(&array[low], &array[j]);
        }
    }

    swap(&array[low + 1], &array[pivot]);

    return low +1;
}
