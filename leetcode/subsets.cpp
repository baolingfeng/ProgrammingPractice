#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res = subsets2(nums);
        vector<int> empty;
        res.push_back(empty);

        return res;
    }
    vector<vector<int> > subsets2(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 0)
        {
            return res;
        }

        if(nums.size() == 1)
        {   
            //vector<int> temp(1, nums[0]);
            res.push_back(nums);
            return res;
        }

        //cout<<nums.size()<<endl;

        vector<int>::iterator middle = nums.begin() + nums.size()/2;
        vector<int> left(nums.begin(), middle);
        vector<int> right(middle, nums.end());

        vector<vector<int> > res1 = subsets2(left);
        vector<vector<int> > res2 = subsets2(right);

        res.insert(res.end(), res1.begin(), res1.end());
        res.insert(res.end(), res2.begin(), res2.end());

        for(int i=0; i<res1.size(); i++)
        {
            for(int j=0; j<res2.size(); j++)
            {
                vector<int> v;
                //v.reserve(res1[i].size() + res2[j].size());
                v.insert(v.end(), res1[i].begin(), res1[i].end());
                v.insert(v.end(), res2[j].begin(), res2[j].end());
                sort(v.begin(), v.end());

                res.push_back(v);
            }
        }

        return res;
    }


};

int main(int argc, char const *argv[])
{
    Solution s;

    const int arr[] = {4, 1, 0};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<vector<int> > res = s.subsets(nums);
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