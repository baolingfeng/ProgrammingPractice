#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int distinct = 1;
        int lastPosition = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                distinct++;
                nums[lastPosition++] = nums[i];
            }
        }

        return distinct;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {1, 1, 2};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );


    int len = s.removeDuplicates(nums);
    cout<<len<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}