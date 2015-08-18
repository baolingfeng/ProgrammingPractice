#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        num1 = strip(num1);
        num2 = strip(num2);

        if(num1 == "0" || num2 == "0") return "0";

        string res = "";
        int k = 1;
        for(int i=num1.length()-1; i>=0; i--)
        {   
            int n = num1[i] - '0';
            int add = 0;
            string sum = "";
            for(int j=num2.length()-1; j>=0; j--)
            {
                int m = num2[j] - '0';

                int mul = m * n + add;
                sum += (mul%10 + '0');
                add = mul / 10;
            }
            if(add>0) sum += (add + '0');

            if(res.length() == 0)
            {
                res = sum;
            }
            else
            {
                string temp = "";
                int j = 0;
                while(j<k)
                {
                    temp += res[j++];
                }

                int add = 0;
                while(j<res.length())
                {
                    int m = (sum[j-k] - '0') + (res[j] - '0') + add;
                    if(m>9)
                    {
                        m -= 10;
                        add = 1;
                    }
                    else
                    {
                        add = 0;
                    }
                    temp += (m + '0');
                    j++;
                }

                j = res.length() - k;
                while(j < sum.length())
                {
                    int m = (sum[j] - '0') + add;
                    if(m>9)
                    {
                        m -= 10;
                        add = 1;
                    }
                    else
                    {
                        add = 0;
                    }
                    temp += (m + '0');
                    j++;
                }
                k++;
                if(add>0) temp += (add + '0');

                res = temp;
            }
            
        }

        int i = 0;
        int j = res.length() - 1;
        while(i<j)
        {
            char temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            i++;
            j--;
        }

        return res;
    }

    string strip(string num)
    {
        int i = 0;
        while(i < num.length())
        {
            if(!(num[i] == ' ' || num[i] == '0'))
            {
                break;
            }
            i++;
        }

        if(i >= num.length())
        {
            return "0";
        }

        return num.substr(i);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.multiply("000", "321");
    return 0;
}