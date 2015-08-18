#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int m;
        while(l <= r)
        {   
            m = (l + r) / 2;
            if(nums[m] == target)
            {
                return m;
            }
            else if(target < nums[m])
            {
                if(m == 0 || target > nums[m-1])
                {
                    return m;
                }
                r = m - 1;
            }
            else
            {
                if(m == nums.size()-1 || target < nums[m+1])
                {
                    return m + 1;
                }
                l = m + 1;
            }
        }

        //return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    const int arr[] = {1,3};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    cout<<s.searchInsert(nums, 2);

    
    return 0;
}