#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water. 
解题思路：两个指针i, j分别从前后向中间移动，两个指针分别表示容器的左右边界。
每次迭代用当前的容量更新最大容量，然后把高度小的边界对应的指针往中间移动一位。       
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int area = 0;
        while(i < j)
        {
            int temp = min(height[i], height[j]) * (j - i);
            if(temp > area)
            {
                area = temp;
            }

            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    cout<<s.maxArea(height);

    return 0;
}