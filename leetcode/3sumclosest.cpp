#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = INT_MAX;
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;

            int target2 = target - nums[i];

            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] < target2)
                {
                    if(target2 - nums[j] - nums[k] <= closest)
                    {
                        closest = target2- nums[j] - nums[k];
                        res = nums[i] + nums[j] + nums[k];
                    }
                    
                    j++;
                }
                else if(nums[j] + nums[k] > target2)
                {
                    if(nums[j] + nums[k] - target2 <= closest)
                    {
                        closest = nums[j] + nums[k] - target2;
                        res = nums[i] + nums[j] + nums[k];
                    }                  
                    k--;
                }
                else
                {
                    return target;
                }

            }
        }
        //cout<<closest<<endl;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-3);
    //nums.push_back(-1);
    //nums.push_back(4);
    
    cout<<s.threeSumClosest(nums, 1);
    //for(int i=0; i<res.size(); i++)
    //{
    //    cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
    //}
    return 0;
}