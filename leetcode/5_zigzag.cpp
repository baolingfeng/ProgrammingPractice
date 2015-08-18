#include<iostream>
#include<vector>
using namespace std;
/*
题目：The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:

P   A   H   N
A P L S I I G
Y   I   R

解题思路： Z字形。 找规律， 第一和最后一行的index之间的step是 2*row-2, 然后从高到低， 每一行的index之间的step为
step-2*i, 2*i, step-2*i, 2i, ....它们之间的step是交替的。
 */
class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> res;
        int step = 2 * numRows - 2;

        if(numRows == 1)
        {
            return s;
        }

        for(int i=0; i<numRows; i++)
        {
            int k = step - 2 * i;
            //cout<<k<<endl;
            int j = i;
            while(j < s.length())
            {   
                res.push_back(s[j]);
                
                if(k == 0 || k == step)
                {
                    j += step;
                }
                else
                {
                    j += k;
                    k = step - k;
                }

            }
            
        }

        string ret = "";
        for(int i=0; i<res.size(); i++)
        {
            ret += res[i];
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.convert("ABCD", 4);

    return 0;
}