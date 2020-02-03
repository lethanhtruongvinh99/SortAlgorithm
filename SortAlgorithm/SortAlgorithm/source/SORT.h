#include <iostream>
using namespace std;

#ifndef __SORT_H__
#define __SORT_H__
void createArr(int*&, int);
void equal(int*, int*, int);
void copyArr(int*,int*, int);
void output(int*, int);
void sort(int*, int, void(*method)(int*, int));
void sort(int*, int,int, void(*method)(int*, int ,int));
void sort(int*, int*, int*,int,int, void(*method)(int*, int*, int*,int ,int));
void bubble(int*, int);
void selection(int*, int);
void insertion(int*, int);
void heapify(int*, int, int);
void heapSort(int*, int);
void quick(int*, int,int);
void quickReverse(int*, int, int);
void merge(int*,int*, int*,int,int);
void mergeSort(int*, int*,int*,int,int);
void countSourt(int*, int,int);
int getMax(int*, int);
void radix(int*, int);
void flash(int*, int);
void deleteArr(int*);
#endif