#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
题目：Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321 
解题思路：主要注意溢出， 返回0
 */
class Solution {
public:
    int reverse(int x) {
        const int MAX_INT = 2147483647;
        const int MIN_INT = -2147483647;

        if(x == 0) return 0;

        int len = lenOfInteger(x);

        int sign = 1;
        if(x < 0)
        {
            x = -x;
            sign = -1;
        }

        long sum = 0;
        while(x != 0)
        {
            long d = x % 10;
            long power = mypow(10, len-1);
            long increment = power * d;
            if(increment < 0)
            {
                return 0;
            }
            
            if(MAX_INT - sum < increment)
            {
                return 0;
            }
            sum += increment;
            x /= 10;
            len--;

            //cout<<len<<endl;
        }
        
        return sum * sign;
    }

    long mypow(int base, int m)
    {
        long res = 1;

        for(int i=0; i<m; i++)
        {
            res = res * base;
        }
        return res;
    }

    int lenOfInteger(int x)
    {   
        int len = 0;
        while(x != 0)
        {
            len += 1;

            x /= 10;
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.reverse(321);
    return 0;
}