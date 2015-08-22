#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch2(s, p, 0, 0);
    }

    bool isMatch2(string s, string p, int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        if(i >= s.length() && j>= p.length())
        {
            return true;
        }
        else if(i == s.length() || j == p.length())
        {
            return false;
        }

        if(p[j] != '*')
        {
            if(s[i] == p[j] || p[j] == '?')
            {
                return isMatch2(s, p, i+1, j+1);
            }
            return false;
        }
        else
        {
            if(j == p.length()-1)
            {
                return true;
            }

            int m = j + 1;
            while((p[m] == '*' || p[m] == '?') && m < p.length()) m++;

            int n = i ;
            while(n < s.length())
            {
                if(s[n] == p[m])
                {
                    return isMatch2(s, p, n, m);
                }

                n++;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.isMatch("aa", "a")<<endl;
    cout<<s.isMatch("aa", "aa")<<endl;
    cout<<s.isMatch("aaa", "a")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("aa", "?*")<<endl;
    cout<<s.isMatch("aab", "a*b*")<<endl;
    return 0;
}