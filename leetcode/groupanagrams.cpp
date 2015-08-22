#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > hash;
        vector<vector<string> > res;

        for(int i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());

            if (hash.find(s) != hash.end())
            {
                hash[s].push_back(strs[i]);
            }
            else
            {
                vector<string> v;
                v.push_back(strs[i]);
                hash[s] = v;
            }
        }

        for(map<string, vector<string> >::iterator it = hash.begin(); it != hash.end(); it++)
        {
            vector<string> v = it->second;
            sort(v.begin(), v.end());
            res.push_back(v);
        }

        return res;
    }
};  

int main(int argc, char const *argv[])
{
    
    Solution s;
    string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs(arr, arr+6);

    vector<vector<string> > res = s.groupAnagrams(strs);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
