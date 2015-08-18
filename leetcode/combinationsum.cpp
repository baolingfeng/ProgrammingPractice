#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> s;
        
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, target, s, res);

        return res;
    }

    void combinationSum2(vector<int>& candidates, int target, vector<int> s, vector<vector<int> >& res)
    {
        if(target == 0)
        {
            //sort(s.begin(), s.end());
            res.push_back(s);
            return;
        }

        for(int i=0; i<candidates.size(); i++)
        {
            if(target-candidates[i] < 0) break;

            if(s.size()>0 && candidates[i] < s[s.size()-1]) continue;

            s.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], s, res);
            s.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    
    Solution s;
    const int arr[] = {8, 7, 4, 3};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<vector<int> > res = s.combinationSum(nums, 11);

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