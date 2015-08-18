#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays.
解题思路： 
遍历两个数组， 按大小存储在另外一个数组中，再计算中位数。 注意偶数时中间两个数取平均。
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i, j;
        vector<int> order;

        i = j = 0;
        while(i<m && j<n)
        {
            if(nums1[i] < nums2[j])
            {
                order.push_back(++i);
            }
            else
            {
                order.push_back(-(++j));
            }
        }

        while(i<m)
        {
            order.push_back(++i);
        }

        while(j<n)
        {
            order.push_back(-(++j));
        }

        for(int i=0; i<order.size(); i++)
        {
            cout<<order[i]<<" ";
        }

        int median = (m + n) / 2;
        if((m + n) % 2 == 0)
        {   
            int v1 = getOrderValue(nums1, nums2, order[median-1]);
            int v2 = getOrderValue(nums1, nums2, order[median]);

            return (v1 + v2) * 1.0 / 2;
        }
        else
        {
            return getOrderValue(nums1, nums2, order[median]);
        }

    }

    int getOrderValue(vector<int>& nums1, vector<int>& nums2, int index)
    {
        if(index > 0)
        {
            return nums1[index-1];
        }
        else
        {
            return nums2[-index-1];
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);

    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);

    cout<<s.findMedianSortedArrays(nums1, nums2);

    return 0;
}