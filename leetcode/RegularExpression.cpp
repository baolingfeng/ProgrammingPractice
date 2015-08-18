#include<iostream>

using namespace std;
/*
题目： '.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
解题思路：
动态规划， 递归。
如果字符后面没有*号， 则直接匹配两个字符串的当前字符， 然后再递归s+1, 和p+1是否匹配
如果字符后面是*号， 则用一个循环，循环的条件是s的当前字符符合条件则s往前遍历；循环中用递归匹配s和p+2，即正则去掉当前的*。
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch2(s.c_str(), p.c_str());
    }

    bool isMatch2(const char* s, const char* p)
    {
        if(*p == 0) return *s == 0;

        if(*(p+1) != '*')
        {
            if(*s == *p || (*p == '.' && *s != 0))
            {
                return isMatch2(s+1, p+1);
            }
            return false;
        }
        else
        {
            while(*s == *p || (*p == '.' && *s != 0))
            {
                if(isMatch2(s, p+2))
                {
                    return true;
                }
                s++;
            }
            return isMatch2(s, p+2);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.isMatch("aa", "a")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    return 0;
}