#ifndef SORTINGFUNCTIONS_H
#define SORTINGFUNCTIONS_H

#include<iostream>
#include<vector>
#include"StoreItem_Class.h"

void quickSort(std::vector<StoreItem>& array, int left, int pivot);
int partition(std::vector<StoreItem>& array, int left, int pivot);
void swap(StoreItem *a, StoreItem *b);
std::vector<StoreItem> reverseSortedVector(const std::vector<StoreItem> items);

#endif // SORTINGFUNCTIONS_H
