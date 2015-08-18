#include<iostream>
#include<limits.h>
using namespace std;
/*
题目：Implement atoi to convert a string to an integer.
解题思路：
1. 如果前面有空格字符， 先去掉
2. 注意如果有正负号， 处理
3. 如果有非法字符， 停止处理， 返回前面的数字
4. 如果溢出， 正数返回INT_MAX, 负数返回INT_MIN
5. sum 用long long存储防止溢出
 */
class Solution {
public:
    int myAtoi(string str) {
        //int MAX_INT = 2147483647;
        //int MIN_INT = -2147483648;

        int i = 0;

        while(str[i] == ' ' or str[i] == '\t') i++;

        int sign = 1;
        if(str[i] == '+')
        {
            i++;
        }
        else if(str[i] == '-')
        {
            sign = -1;
            i++;
        }

        long long sum = 0;
        int upper = sign > 0 ? INT_MAX : INT_MIN;
        //cout<<INT_MAX<<"/"<<INT_MIN<<endl;
        while(i < str.length())
        {
            if(str[i] >= '0' && str[i] <= '9')
            {   
                sum = sum * 10 +  (str[i] - '0');
                if(sign > 0 && sum > INT_MAX)
                {
                    return INT_MAX;
                }

                if(sign < 0 && -sum < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                break;
            }

            i++;
        }

        cout<<sign<<"/"<<sum<<endl;
        return sum * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.myAtoi("2147483648")<<endl;
    return 0;
}