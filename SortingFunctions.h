#ifndef SORTINGFUNCTIONS_H
#define SORTINGFUNCTIONS_H

#include<iostream>
#include<vector>

void quickSort(std::vector<double>& array, int left, int pivot);
int partition(std::vector<double>& array, int left, int pivot);
void swap(double *a, double *b);

#endif // SORTINGFUNCTIONS_H
