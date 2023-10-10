//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
//
//
//
// 示例 1：
//
//
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//
//
// 示例 2：
//
//
//输入：nums = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：nums = [0]
//输出：[]
//
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 3000
// -10⁵ <= nums[i] <= 10⁵
//
// Related Topics 数组 双指针 排序 👍 4779 👎 0

#include<bits/stdc++.h>

using namespace std;
/*算法流程：
1.特判，对于数组长度n，如果数组为 null 或者数组长度小于3，返回[]。
2.对数组进行排序。
3.遍历排序后数组：
(1)若 nums[i]>0:因为已经排序好，所以后面不可能有三个数加和等于 00，直接返回结果。
(2)对于重复元素：跳过，避免出现重复解
(3)令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
      当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,RL,R 移到下一位置，寻找新的解
      若和大于 00，说明 nums[R]nums[R] 太大，RR 左移
      若和小于 00，说明 nums[L]nums[L] 太小，LL 右移*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
       int len=nums.size();
       vector<vector<int>> result;
       sort(nums.begin(),nums.end());

       for(int i=0;i<len;i++)
       {
           if(nums[i]>0)
               return result;
           if(i>0 && nums[i]==nums[i-1])
           {
               continue;
           }
           int left=i+1;
           int right=len-1;
           while(left<right)
           {
               if(nums[i]+nums[left]+nums[right]>0)
               {
                   right--;
               }
               else if(nums[i]+nums[left]+nums[right]<0)
               {
                   left++;
               }
               else
               {
                   result.push_back({nums[i],nums[left],nums[right]});
                   while(left<right && nums[left]==nums[left+1]) {left++;}
                   while(left<right && nums[right]==nums[right-1]) {right--;}
                   left++;
                   right--;
               }
           }
       }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
