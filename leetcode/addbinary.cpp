#include "common_header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        bool overflow = false;

        if(a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        } 

        string s = "";
        for(int i=0; i<a.length()-b.length(); i++)
        {
            s += "0";
        }
        b = s + b;

      
        string res = "";
        int i = b.length()-1;
        for(; i >= 0; i--)
        {
            if(a[i] == b[i])
            {
                res += overflow ? "1" : "0";

                overflow = (a[i] == '1');
            }
            else
            {
                res += overflow ? "0" : "1";
            }
        }

        if(overflow) res += "1";

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.addBinary("1101010", "1");

    return 0;
}