#include <iostream>
#include <vector>

using namespace std;

/*
解题思路： 先对角线反转， 再上下反转
 */

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size() - 1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; i+j<=n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][n-i];
                matrix[n-j][n-i] = temp;
            }
        }

        

        for(int i=0; i<=n/2; i++)
        {
            for(int j=0; j<=n; j++)
            {
                //cout<<matrix[i][j]<<" "<<matrix[n-i][j]<<endl;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-i][j];
                matrix[n-i][j] = temp;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr1[] = {1, 2, 3};
    vector<int> v1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
    const int arr2[] = {4, 5, 6};
    vector<int> v2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    const int arr3[] = {7, 8, 9};
    vector<int> v3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    //const int arr4[] = {1, 2, 3, 4};
    //vector<int> v4 (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]) );

    vector<vector<int> > matrix;
    matrix.push_back(v1); matrix.push_back(v2); matrix.push_back(v3); //matrix.push_back(v4);

    s.rotate(matrix);

    int n = matrix.size() - 1;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {   
           
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}