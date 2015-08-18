#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        //if(nums.size() == 0) return res;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        //cout<<n-2;
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;

            int target = 0 - nums[i];

            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] < target)
                {
                    j++;
                }
                else if(nums[j] + nums[k] > target)
                {
                    k--;
                }
                else
                {
                    vector<int> s;
                    s.push_back(nums[i]);
                    s.push_back(nums[j]);
                    s.push_back(nums[k]);
                    res.push_back(s);

                    int temp = j + 1;
                    while(temp<k && nums[j] == nums[temp]) temp++;
                    j = temp;

                    temp = k - 1;
                    while(temp>j && nums[k] == nums[temp]) temp--;
                    k = temp;
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
    //nums.push_back(-1);
    //nums.push_back(0);
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(-1);
    //nums.push_back(4);
    
    vector<vector<int> > res = s.threeSum(nums);
    //for(int i=0; i<res.size(); i++)
    //{
    //    cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
    //}
    return 0;
}