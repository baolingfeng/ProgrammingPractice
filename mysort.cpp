#include "mysort.h"

using namespace std;


void print_array(int a[], int size)
{
    for(int i=0; i<4; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void swap(int a[], int i, int j)
{
    //cout<<a[i]<<" "<<a[j]<<endl;
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
    //cout<<a[i]<<" "<<a[j]<<endl;
}

void insert_sort(int a[], int size)
{
    /*
    基本思想
        假设待排序的记录存放在数组R[1..n]中。
        初始时，R[1]自成1个有序区，无序区为R[2..n]。
        从i=2起直至i=n为止，依次将R[i]插入当前的有序区R[1..i-1]中，生成含n个记录的有序区。
    */
    for(int i=1; i<size; i++)
    {
        int j = i;
        if(a[i-1] > a[i])
        {
            for(; j>0; j--)
            {
                if(a[j]<a[j-1])
                {
                    swap(a, j, j-1);
                }
            }
        }
    }
}

void bubble_sort(int a[], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(a[i] > a[j])
            {
                swap(a, i, j);
            }    
        }
        print_array(a, size);
    }
}

//[left, middle), [middle, right)
void merge(int a[], int left, int middle, int right)
{
    int i, j, k;
    i = left;
    j = middle;

    int size = right - left;
    int* temp = new int[size];

    k = 0;
    while(i<middle && j<right)
    {
        if(a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while(i<middle)
    {
        temp[k++] = a[i++];
    }
    while(j<right)
    {
        temp[k++] = a[j++];
    }

    for(int i=0; i<size; i++)
    {
        a[i+left] = temp[i]; //index attention 
    }

    delete[] temp;
}

void merge_sort1(int a[], int left, int right)
{
    if(left + 1 < right)
    {
        int middle = (right + left) / 2;
        merge_sort1(a, left, middle);
        merge_sort1(a, middle, right);
        
        merge(a, left, middle, right);
    }
}

void merge_sort(int a[], int size)
{
    merge_sort1(a, 0, size);
}

void quick_sort1(int a[], int left, int right)
{   
    cout<<left<<" "<<right<<endl;
    int i=left;
    int j=right;

    int base = a[(left+right)/2]; 
    do
    {
        while(a[j]>base) j--;
        
        while(a[i]<base) i++;

        if(i<=j) 
        {
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
            //swap(a, i, j);
            i++; j--;
        }
    }while(i<=j);

    //print_array(a, 4);
    //swap(a, left, i);
    
    if(left < j) quick_sort1(a, left, j);
    if(i < right) quick_sort1(a, i, right);
}

void quick_sort(int a[], int size)
{
    quick_sort1(a, 0, size-1);
}

void min_heapify(int a[], int size, int i)
{
    int left = (i<<1) + 1;
    int right = (i<<1) + 2;
    
    int minimum = 0;
    if(left < size && a[left] < a[i])
    {
        minimum = left;
    }
    else
    {
        minimum = i;
    }

    if(right < size && a[right] < a[minimum])
    {
        minimum = right;
    }

    if(minimum != i)
    {
        swap(a, i, minimum);
        min_heapify(a, size, minimum);
    }
}

void build_min_heap(int a[], int size)
{
    for(int i=size/2-1; i>=0; i--)
    {
        min_heapify(a, size, i);
    }
}

void heap_sort(int a[], int size)
{
    build_min_heap(a, size);
    
    for(int i=size-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        size--;
        min_heapify(a, size, 0);
    }
}

int main()
{
    cout<<"implement some sort algorithm..."<<endl;

    int a[] = {4, 3, 1, 2};
    heap_sort(a, 4);
    
    print_array(a, 4);

    return 1;
}
