#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if(st.empty())
            {
                return false;
            }
            else
            {
                char t = st.top();
                if(t == '(' && s[i] == ')' || 
                    (t == '[' && s[i] == ']') ||
                    (t == '{' && s[i] == '}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout<<s.isValid("()[]{}")<<endl;
    cout<<s.isValid("([)]")<<endl;

    return 0;
}