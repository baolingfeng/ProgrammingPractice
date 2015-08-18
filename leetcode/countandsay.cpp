#include<iostream>
#include<sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        char buff[33];
        for(int i=1; i<n; i++)
        {   
            //res += current + ", ";
            
            string next = "";
            int count = 1;
            char pre = current[0];
            for(int j=1; j<current.length(); j++)
            {
                if(current[j] == pre)
                {
                    count++;
                }
                else
                {
                    //itoa(count, buff, 33);

                    next += to_string(count) + pre; 
                    count = 1;
                }

                pre = current[j];
            }

            //itoa(count, buff, 33);
            next += to_string(count) + pre; 

            current = next;
        }

        return current;    
    }

    string to_string(int count)
    {
        stringstream ss;
        ss<<count;
        return ss.str();
    }
   
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.countAndSay(5);

    return 0;
}