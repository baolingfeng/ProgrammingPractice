#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);

        for(int k=1; k<=rowIndex; k++)
        {
            for(int i=k-1; i>=1; i--)
            {
                res[i] = res[i] + res[i-1];
            }
            
        }
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> res = s.getRow(5);
    for(int i=0; i<res.size(); i++)
    {
        
        cout<<res[i]<<" ";
    }

    return 0;
}