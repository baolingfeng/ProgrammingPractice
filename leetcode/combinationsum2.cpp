#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> s;

        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0, s, res); 

        return  res;
    }

    void combinationSum(vector<int>& candidates, int target, int index, vector<int> s, vector<vector<int> >& res)
    {
        if(target < 0)
        {
            return;
        }

        if(target == 0)
        {
            //cout<<s.size();
            res.push_back(s);
            return;
        }
        else
        {
            for(int i=index; i<candidates.size(); i++)
            {
                //cout<<i<<endl;
                //if(i>0 && candidates[i] == candidates[i-1]) continue;
                
                //
                target -= candidates[i];
                s.push_back(candidates[i]);
                combinationSum(candidates, target, i+1, s, res);
                s.pop_back();
                target += candidates[i];

                while(i<candidates.size()-1 && candidates[i] == candidates[i+1]) i++;  
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {10,1,2,7,6,1,5};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<vector<int> > res = s.combinationSum2(nums, 8);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}