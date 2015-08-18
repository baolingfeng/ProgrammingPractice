#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "") return 0;

        stack<int> stack1;
        stack<int> stack2;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
            {
                stack1.push(i);
            }
            else
            {
               if(stack1.empty())
               {
                    stack2.push(i);
               }
               else
               {
                    stack1.pop();
               }

            }
        }

        if(stack1.empty() && stack2.empty()) return s.length();

        vector<int> indexes;
        //indexes.push_back(0);
        //indexes.push_back(s.length()-1);
        while(!stack1.empty())
        {
            indexes.push_back(stack1.top());
            stack1.pop();
        }
        while(!stack2.empty())
        {
            indexes.push_back(stack2.top());
            stack2.pop();
        }
        sort(indexes.begin(), indexes.end());


        int l1 = indexes[0] - 0;
        int l2 = s.length() - indexes[indexes.size()-1] - 1;
        int maxLen = l1 > l2 ? l1 : l2;
        for(int i=0; i<indexes.size()-1; i++)
        {
            //cout<<indexes[i]<<endl;
            int len = indexes[i+1] - indexes[i] -1 ;
            if(len > maxLen)
            {
                maxLen = len;
            }
        }

        return maxLen;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.longestValidParentheses("())()");

    return 0;
}