#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> v(n, 0);
       v[0] = 1;
       for(int i=0; i<m; i++)
       {
            for(int j=1; j<n; j++)
            {
                v[j] = v[j-1] + v[j];
            } 
       }
       return v[n-1];
    }

    /*
    Time execute limit
    int uniquePaths(int m, int n) {
        int count = 0;
        uniquePaths2(1, 1, m, n, count);

        return count;
    }

    void uniquePaths2(int pi, int pj, int m, int n, int& count)
    {
        if(pi == m && pj == n)
        {
            count += 1;
        }
        else
        {
            if(pi+1 <= m)
                uniquePaths2(pi+1, pj, m, n, count);
            if(pj+1 <= n)
                uniquePaths2(pi, pj+1, m, n, count);

        }
    }
    */
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.uniquePaths(5, 4);
    return 0;
}