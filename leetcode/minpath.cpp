#include "common_header.h"

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.size() <= 0 || grid[0].size() <= 0) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > path(m, vector<int>(n, 0));

        path[0][0] = grid[0][0];

        for(int i=1; i<m; i++)
        {
            path[i][0] = path[i-1][0] + grid[i][0];
        }

        for(int i=1; i<n; i++)
        {
            path[0][i] = path[0][i-1] + grid[0][i];
        }

        int minSum = INT_MAX;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
            }
        }

        

        return path[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr1[] = {0, 1};
    vector<int> v1(arr1, arr1+2);
    const int arr2[] = {1, 0};
    vector<int> v2(arr2, arr2+2);
    //const int arr3[] = {1, 2, 3, 4, 5};
    //vector<int> v3(arr3, arr3+5);
    


    vector<vector<int> > grid;
    grid.push_back(v1);
    grid.push_back(v2);
    //grid.push_back(v3);

    cout<<s.minPathSum(grid);

    return 0;
}