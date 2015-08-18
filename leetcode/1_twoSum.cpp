#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
题目：Given an array of integers, find two numbers such that they add up to a specific target number.

解题思路： 使用一个hash记录数组中每一个值的index， 对于重复的数字， hash<key, value>中value用一个list存。 
先遍历一遍数组， 计算hash。 然后再次遍历， 查找[target-当前数字]是否也在hash中。
注意结果中 index1 < index2 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int> > hash;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            if(hash.find(nums[i]) != hash.end())
            {
                vector<int> v;
                v.push_back(i);
                hash[nums[i]] = v;
            }
            else
            {
                hash[nums[i]].push_back(i);
            }
           
        }
        //cout<<"............"<<endl;
        for(int i=0; i<nums.size(); i++)
        {
            int v = target - nums[i];

            if(hash.find(v) != hash.end())
            {   
                //cout<<v<<endl;
                vector<int> indexes = hash[v];
                for(int j=0; j<indexes.size(); j++)
                {   
                    if(i < indexes[j])
                    {
                        res.push_back(i+1);
                        res.push_back(indexes[j]+1);
                    }
                }
            }
        }
        return res;
        /*
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());

        int i = 0;
        int j = sortNums.size() - 1;

        vector<int> res; 
        while(i<j)
        {
            if(sortNums[i] + sortNums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                i++;
                j--;
            }
            else if(sortNums[i] + sortNums[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        for(int i=0; i<res.size(); i+=2)
        {
            int index1 = res[i];
            int index2 = res[i+1];
            cout<<index1<<"/"<<index2<<endl;
            int val1 = sortNums[index1];
            int val2 = sortNums[index2];

            int res1, res2;
            if(val1 == val2)
            {
                vector<int>::iterator it = find(nums.begin(), nums.end(), val1);
                res1 = it - nums.begin()  + 1;
                vector<int>::iterator it2 = find(it+1, nums.end(), val2);
                res2 = it2 - nums.begin() + 1;
            }
            else
            {
                vector<int>::iterator it = find(nums.begin(), nums.end(), val1);
                vector<int>::iterator it2 = find(nums.begin(), nums.end(), val2);
                res1 = it - nums.begin()  + 1;
                res2 = it2 - nums.begin() + 1;
            }

            if(res1 > res2)
            {
                int temp = res1;
                res1 = res2;
                res2 = temp;
            }
            res[i] = res1;
            res[i+1] = res2;
        }

        return res;
        */
    }

    //void reverseTwoSum(vector<int>& nums, int k, )
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(0);
    vector<int> res = s.twoSum(nums, 0);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}