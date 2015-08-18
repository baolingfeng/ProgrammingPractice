#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int last = nums[n];
        int i = n;
        while(i>0 && nums[i] <= nums[i-1])
        {
            i--;
        }
        i -= 1;

        if(i < 0)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {   
            int j = n;
            while(j>i && nums[j] <= nums[i])
            {
                j--;
            }

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            sort(nums.begin()+i+1, nums.end());
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {1, 3, 2};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    s.nextPermutation(nums);

    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}