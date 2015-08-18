#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string prefix = strs[0];

        for(int i=1; i<strs.size(); i++)
        {
            int j = 0;

            while(j<prefix.length() && j<strs[i].length() && strs[i][j] == prefix[j])
            {
                j++;
            }

            if(j == 0) return "";

            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> strs;

    strs.push_back("abab");
    strs.push_back("ab");

    cout<<s.longestCommonPrefix(strs);
    return 0;
}