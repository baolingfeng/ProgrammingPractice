#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = 0;
        int r = nums.size() - 1;

        int m;
        bool flag = false;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(nums[m] == target)
            {
                flag = true;
                break;
            }
            else if(nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        if(flag)
        {
            int l = m;
            while(l>=0 && nums[l] == nums[m])
            {
                l--;
            }
            int r = m;
            while(r<nums.size() && nums[r] == nums[m])
            {
                r++;
            }
            res.push_back(l+1);
            res.push_back(r-1);
        }
        else
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    const int arr[] = {5};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<int> res = s.searchRange(nums, 8);

    cout<<res[0]<<" "<<res[1];

    return 0;
}