#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int lastMax;
        int n = nums.size() - 1;
        int i=0;
        int step = 0;
        while(curMax < n)
        {
            lastMax = curMax;
            for(; i<=lastMax; i++)
            {
                curMax = max(curMax, i+nums[i]);
                //cout<<curMax;
            }
            step++;
            if(curMax == lastMax) return -1;
        }
        return step;

        /*
        if(nums.size() == 0) return 0;

        int n =nums.size() - 1;
        //int last = nums[n];
        vector<int> v;
        v.push_back(n);

        int step = 0;
        while(true)
        {   
            if(v.size()<=0) break;

            vector<int> temp;
            for(int i=0; i<v.size(); i++)
            {
                int k = v[i];
                int j = k-1;
                
                while(j>=0)
                {
                    if(nums[j] < k-j) break;

                    temp.push_back(j);
                    j--;
                }

                if(j<0) return step;
            }

            v = temp;
            step++;
        }
        
        return step;
        */
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const int arr[] = {2,3,1,1,4};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    cout<<s.jump(nums);

    return 0;
}