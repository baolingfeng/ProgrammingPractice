#include<iostream>
#include<map>
using namespace std;
/*
题目：Given a string, find the length of the longest substring without repeating characters.
解题思路：
map<char, int> hash：存储已经出现过的字符的最后一个index。
last_start: 前面一个不重复子串的起始位置。
len：当前不重复子串的长度。
maxLen: 返回值， 最长的长度。

如果遇到重复的字符 c， 如果last_start比hash中c的index要小， 则需要更新last_start = index + 1;
并且需要更新len = i - index;
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        
        int maxLen = 0;
        int len = 1;
        map<char, int> hash;
        int last_start = 0;

        hash[s[0]] = 0;
        for(int i = 1 ; i < s.length(); i++)
        {
            if(hash.find(s[i]) == hash.end())
            {
                len += 1;
                hash[s[i]] = i;
            }
            else
            {
                if(last_start <= hash[s[i]])
                {
                    len = i - hash[s[i]];
                    last_start = hash[s[i]] + 1;
                    hash[s[i]] = i;
                }
                else
                {
                    len += 1;
                    hash[s[i]] = i;
                }
            }

            if(len > maxLen)
            {
                maxLen = len;
            }
        }
        //cout<<maxLen<<"/"<<len<<endl;
        return maxLen > len ? maxLen : len;
    }


};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.lengthOfLongestSubstring("ccategory");

    return 0;
}