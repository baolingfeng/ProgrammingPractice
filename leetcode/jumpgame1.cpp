#include "common_header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curMax = 0;
        int lastMax;
        int n = nums.size() - 1;
        int i=0;
        //int step = 0;
        while(curMax < n)
        {
            lastMax = curMax;
            for(; i<=lastMax; i++)
            {
                curMax = max(curMax, i+nums[i]);

            }
            //step++;
            if(curMax == lastMax) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {0, 2, 3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout<<s.canJump(nums);

    return 0;
}