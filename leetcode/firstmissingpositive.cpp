#include<iostream>
#include<vector>

using namespace std;

/*
unresolved
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int m = 1;
        int n = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= 0) continue;

            if(nums[i] == m)
            {
                m++;
            }
            else if(nums[i] < n)
            {

            }
        }
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}