#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 0) return res;

        sort(nums.begin(), nums.end());

        while(true)
        {
            vector<int> temp = nums;
            res.push_back(temp);

            if(!nextPermutation(nums)) break;

            
        }

        return res;
    }
    
    bool nextPermutation(vector<int>& nums) {
        
        if(nums.size() <= 1) return false;

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
            return false;
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
        return true;
    }
    
};


int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {1};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<vector<int> > res = s.permuteUnique(nums);
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