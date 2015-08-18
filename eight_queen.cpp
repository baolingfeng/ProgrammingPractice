#include <iostream>
#include "definition.h"

using namespace std;

void permutation(int ColumnIndex[], int queens, int index);

void eight_queen()

{

    const int queens = 8;

    int ColumnIndex[queens];

    for(int i = 0; i < queens; ++ i)
    {
        ColumnIndex[i] = i;
    }
    permutation(ColumnIndex, queens, 0);
}

bool check(int ColumnIndex[], int queens)
{
    for(int i = 0; i < queens; ++ i)
    {

        for(int j = i + 1; j < queens; ++ j)
        {
            if((i - j == ColumnIndex[i] - ColumnIndex[j])
                || (j - i == ColumnIndex[i] - ColumnIndex[j]))
            return false;
        }
    }
    return true;
}

void print_queen(int ColumnIndex[], int queens)
{
    //printf("Solution %d\n", g_number);
    for(int i = 0; i < queens; ++i)
    {
        cout<<ColumnIndex[i]<<" ";
    }
    cout<<endl;
}

void permutation(int ColumnIndex[], int queens, int index)
{
    if(index == queens)
    {
        if(check(ColumnIndex, queens))
        {
            print_queen(ColumnIndex, queens);
        }
    }
    else
    {
        for(int i=index; i<queens; i++)
        {
            myswap(ColumnIndex[i], ColumnIndex[index]);

            permutation(ColumnIndex, queens, index+1);

            myswap(ColumnIndex[index], ColumnIndex[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    eight_queen();
    return 0;
}