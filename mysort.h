#include <iostream>

inline void swap(int &a, int &b) { int t = a; a = b; b = t; }  

void print_array(int a[], int size);
void swap(int a[], int i, int j);

void insert_sort(int a[], int size);
void bubble_sort(int a[], int size);

void merge(int a[], int left, int middle, int right);
void merge_sort(int a[], int size);

void quick_sort(int a[], int size);

void min_heapify(int a[], int size, int i);
void heap_sort(int a[], int size);