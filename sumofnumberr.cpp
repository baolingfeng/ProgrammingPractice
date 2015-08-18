#include <iostream>
#include <vector>

using namespace std;

void sum_of_number(int a[], int size, int sum, int index, vector<int> list)
{
    if(index < 0 || sum < 0)
    {
        return;
    }

    if(sum == a[index])
    {
        for(int i=list.size()-1; i>=0; i--)
        {
            cout<<list[i]<<" ";
        }
        cout<<a[index]<<endl;
    }

    list.push_back(a[index]);
    sum_of_number(a, size, sum-a[index], index-1, list);
    list.pop_back();
    sum_of_number(a, size, sum, index-1, list);
}

int main()
{
    /*
    int a[] = {1,2,1,3,0,1};
    int len = sizeof(a) / sizeof(int);

    int sum = 3;
    vector<int> list;

    sum_of_number(a, len, sum, len-1, list);
    */
    int a = 1;
    int b = 2;
    char * c;
    c = (char *) a;
    cout<<c<<endl;
    //cout<<&c[b];


    return 0;
}