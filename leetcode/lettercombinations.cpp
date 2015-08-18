#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
        {
            return res;
        }

        char d = digits[0];
        vector<string> cset = getChars(d);

        string sub = digits.substr(1);
        vector<string> subres = letterCombinations(sub);

        if(cset.size() == 0)
        {
            return subres;
        }
        else if(subres.size() == 0)
        {
            return cset;
        }
        else
        {
            for(int i=0; i<cset.size(); i++)
            {
                for(int j=0; j<subres.size(); j++)
                {
                    res.push_back(cset[i] + subres[j]);
                }
            }
        }
        return res;
    }

    vector<string> getChars(char digit)
    {   
        vector<string> res;
        if(digit == '0' || digit == '1')
        {
            return res;
        }
        else if(digit == '2')
        {
            res.push_back("a"); res.push_back("b"); res.push_back("c");
        }
        else if(digit == '3')
        {
            res.push_back("d"); res.push_back("e"); res.push_back("f");
        }
        else if(digit == '4')
        {
            res.push_back("g"); res.push_back("h"); res.push_back("i");
        }
        else if(digit == '5')
        {
            res.push_back("j"); res.push_back("k"); res.push_back("l");
        }
        else if(digit == '6')
        {
            res.push_back("m"); res.push_back("n"); res.push_back("o");
        }
        else if(digit == '7')
        {
            res.push_back("p"); res.push_back("q"); res.push_back("r"); res.push_back("s");
        }
        else if(digit == '8')
        {
            res.push_back("t"); res.push_back("u"); res.push_back("v");
        }
        else if(digit == '9')
        {
            res.push_back("w"); res.push_back("x"); res.push_back("y"); res.push_back("z");
        }
        return res;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    string digits = "23";

    vector<string> res = s.letterCombinations(digits);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}