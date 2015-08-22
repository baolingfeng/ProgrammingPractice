#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;

        int i = 0;
        int j = x;
        while(true)
        {
            int n = (i + j) / 2;
            if(i == n) break;

            //cout<<i<<" "<<j<<" "<<n<<endl;

            if(INT_MAX / n < n || n * n > x)
            {
                j = n;
            }
            else
            {
                i = n;
            }
        }

        
        return i;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.mySqrt(1);

    return 0;
}