#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;

        int n = haystack.length() - needle.length() + 1;
        for(int i=0; i<n; i++)
        {
            int j = i;
            int k = 0;
            while(j<haystack.length() && 
                k<needle.length() && 
                haystack[j] == needle[k])
            {
                j++; 
                k++;
            }

            if(k == needle.length())
            {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.strStr("mississippi", "pi");
    return 0;
}