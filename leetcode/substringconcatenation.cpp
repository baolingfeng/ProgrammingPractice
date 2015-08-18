#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> dict;
        map<string, int> dict2;
        vector<int> res;
        int k = 0;
        int n = words.size();

        for(int i=0; i<n ; i++)
        {
            if(dict.find(words[i]) == dict.end())
            {
                dict[words[i]] = 1;
            }
            else
            {
                dict[words[i]] += 1;
            }
            k = words[i].length();
        }

        dict2 = dict;

        //cout<<k<<" "<<n<<endl;

        for(int i=0; i<s.length(); i++)
        {   
            bool flag = true;
            if(i + k*n > s.length()) 
            {
                break;
            }

            for(int j=i; j<i+k*n; j+=k)
            {
                string sub = s.substr(j, k);
                //cout<<i<<" "<<sub<<endl;
                if(dict2.find(sub) == dict2.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    if(dict2[sub] > 0)
                    {
                        dict2[sub] -= 1;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            dict2 = dict;

            if(flag)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "barfoothefoobarman";
    const string arr[] = {"bar", "foo"};
    vector<string> words (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<int> res = s.findSubstring(str, words);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}