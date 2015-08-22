#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool isPositive = true;
        if(n<0)
        {
            isPositive = false;
            n = -n;
        }

        double res = myPow2(x, n);

        if(!isPositive)
        {
            res = 1 / res;
        }
        return res;
    }

    double myPow2(double x, unsigned int n)
    {
        if(n == 0)
        {
            return 1;
        }

        double half = myPow2(x, n>>1);

        return (n&1 == 1 ? x : 1) * half * half;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.myPow(0.2, 2);

    return 0;
}