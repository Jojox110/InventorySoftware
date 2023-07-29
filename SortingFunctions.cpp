#include"SortingFunctions.h"
#include<iostream>
#include<vector>
#include<QString>
#include<QDebug>

void swap(StoreItem *a, StoreItem *b){
    StoreItem tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(std::vector<StoreItem>& array, int left, int pivot){
    if(left < pivot){
        int new_pivot = partition(array, left, pivot);

        quickSort(array, left, new_pivot - 1);
        quickSort(array, new_pivot + 1, pivot);
    }
}

int partition(std::vector<StoreItem>& array, int left, int pivot){
    int low = left - 1;
    int high = pivot - 1;

    for(int j = left; j <= high; j++){
        if(array[j].getPrice() <= array[pivot].getPrice()){
            low++;
            swap(&array[low], &array[j]);
        }
    }

    swap(&array[low + 1], &array[pivot]);

    return low +1;
}

std::vector<StoreItem> reverseSortedVector(const std::vector<StoreItem> items) {
    std::vector<StoreItem> newVector;
    newVector.reserve(items.size());
    for (int i = items.size() - 1; i >= 0; i--) {
        newVector.push_back(items[i]);
    }
    return newVector;
}
