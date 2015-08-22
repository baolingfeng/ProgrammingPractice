#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        
        if(numRows<=0) return res;

        for(int i=0; i<numRows; i++)
        {
            if(res.size() == 0)
            {
                vector<int> v(1, 1);
                res.push_back(v);
                continue;
            }

            vector<int> lastv = res[res.size()-1];

            vector<int> v;
            v.push_back(lastv[0]);
            for(int i=0; i<lastv.size(); i++)
            {
                if(i == lastv.size() - 1)
                {
                    v.push_back(lastv[i]);
                    continue;
                }
                v.push_back(lastv[i] + lastv[i+1]);
            }
            res.push_back(v);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int> > res = s.generate(5);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}