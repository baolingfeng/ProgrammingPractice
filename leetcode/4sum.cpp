#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());

        int len = nums.size();
        for(int i=0; i<len-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<len-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int target2 = target - nums[i] - nums[j];

                int m = j + 1;
                int n = len - 1;

                while(m < n)
                {
                    if(nums[m] + nums[n] < target2)
                    {
                        m++;
                    }
                    else if(nums[m] + nums[n] > target2)
                    {
                        n--;
                    }
                    else
                    {
                        vector<int> s;
                        s.push_back(nums[i]);
                        s.push_back(nums[j]);
                        s.push_back(nums[m]);
                        s.push_back(nums[n]);
                        res.push_back(s);

                        int temp = m + 1;
                        while(temp<n && nums[m] == nums[temp]) temp++;
                        m = temp;

                        temp = n - 1;
                        while(temp>m && nums[n] == nums[temp]) temp--;
                        n = temp;
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    
    vector<vector<int> > res = s.fourSum(nums, 0);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<" "<<res[i][3]<<endl;
    }
    //
    return 0;
}