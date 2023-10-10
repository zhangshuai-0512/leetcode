//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。 
//
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 返回容器可以储存的最大水量。 
//
// 说明：你不能倾斜容器。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
//解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 示例 2： 
//
// 
//输入：height = [1,1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 2 <= n <= 10⁵ 
// 0 <= height[i] <= 10⁴ 
// 
// Related Topics 贪心 数组 双指针 👍 3495 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left=0; //左挡板
        int right=height.size()-1; //右挡板
        int max=0; //最大容水量
        //不断移动左右挡板，更新最大容水量
        while(left!=right)
        {
            int heigh=height[left]<height[right]? height[left]:height[right];
            int width=right-left;
            int volume=heigh*width; //当前两块挡板容水量
            if(volume>max)
            {   //更新最大容水量
                max=volume;
            }
            //向中间移动左右挡板中较低的那一块
            if(height[left]<height[right])
            {
                left+=1;
            }
            else{
                right-=1;
            }
        }
        return max;
    }
};
//leetcode submit region right(Prohibit modification and deletion)
