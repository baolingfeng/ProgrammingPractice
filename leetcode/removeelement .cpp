#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while(true)
        {
            while(i<=j && nums[i] != val) i++;
            while(j>=i && nums[j] == val) j--;

            if(i>=j) break;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
       
       return j+1;
    }
};

int main(int argc, char const *argv[])
{
     Solution s;
    const int arr[] = {3, 3};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );


    int len = s.removeElement(nums, 3);
    cout<<len<<endl;
    for(int i=0; i<len; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}