#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT. 

注意：如果循环减divisor， 遇到INT_MAX/1, 时间过长
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;

        int sign = 1;
        if(dividend < 0 && divisor > 0 || 
            (dividend > 0 && divisor < 0))
        {
            sign = -1;
        }

        unsigned int nDividend = dividend < 0 ? -dividend : dividend;
        unsigned int nDivisor  = divisor < 0 ? -divisor : divisor;

        int res = 0;
        while(nDivisor < nDividend) {
            unsigned int i = 1;
            unsigned int temp = nDivisor;

            while(temp<<1 < nDividend)
            {
                i = i<<1;
                temp = temp<<1;
                //cout<<i<<endl;
            }
            nDividend = nDividend - temp;
            
            res += i;
        }

        if(res == INT_MAX && sign>0)
        {

            return INT_MAX;
        }

        if(nDivisor == nDividend)
        {
            res++;
        }    

        return sign * res;
       
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.divide(INT_MIN, -1);

    return 0;
}