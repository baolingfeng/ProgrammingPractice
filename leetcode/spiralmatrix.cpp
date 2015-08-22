#include "common_header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;

        int m = matrix.size();
        if(m <= 0) return res;

        int n = matrix[0].size();
        for (int k = 0; k <= m / 2; ++k)
        {
            for (int i = k; i<n-k && k<m; ++i)
            {
                res.push_back(matrix[k][i]);
            }         

            for(int i = k+1; i < m-k && k<n; ++i)
            {
                res.push_back(matrix[i][n-k-1]);
            }

            for(int i = n-k-2; i >= k && k<m; --i)
            {
                res.push_back(matrix[m-k-1][i]);
            }

            for(int i = m-k-2; i > k && k<n; --i)
            {
                res.push_back(matrix[i][k]);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr1[] = {1, 2, 3};
    vector<int> row1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    const int arr2[] = {4, 5, 6};
    vector<int> row2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    const int arr3[] = {7, 8, 9};
    vector<int> row3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));

    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    //matrix.push_back(row3);
   
    vector<int> res = s.spiralOrder(matrix);

    for (int i = 0; i < res.size(); ++i)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}