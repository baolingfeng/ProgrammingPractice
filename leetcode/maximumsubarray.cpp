#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        int maxElement = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];

            if(nums[i] > maxElement)
            {
                maxElement = nums[i];
            }

            if(sum < 0)
            {
                sum = 0;
            }
            else
            {
                if(sum > maxSum)
                {
                    maxSum = sum;
                }
            }
        }

        if(maxElement < 0) return maxElement;

        return maxSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {-2};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    cout<<s.maxSubArray(nums);

    return 0;
}