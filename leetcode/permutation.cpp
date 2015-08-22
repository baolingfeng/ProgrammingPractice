#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        permute2(nums, 0, nums.size()-1, res);

        return res;
    }

    void permute2(vector<int>& nums, int from, int to, vector<vector<int> >& res)
    {
        if(to<0) return;

        if(from == to)
        {
            vector<int> s = nums;
            res.push_back(s);
            return;
        }
        else
        {
            for(int i=from; i<=to; i++)
            {
                myswap(nums[i], nums[from]);
                permute2(nums, from+1, to, res);
                myswap(nums[i], nums[from]);
            }
        }
        return ;
    }

    void myswap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
        //b = a - b;
        //a = a - b;
        //b = b + a;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {1, 1, 2};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<vector<int> > res = s.permute(nums);
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