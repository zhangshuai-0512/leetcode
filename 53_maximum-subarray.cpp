//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 子数组 是数组中的一个连续部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [5,4,-1,7,8]
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
//
// Related Topics 数组 分治 动态规划 👍 6290 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int maxans=dp[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            maxans=max(maxans,dp[i]);
        }
        return maxans;
    }


    /*贪心算法
    int maxSubArray(vector<int> &nums)
    {
        int ans = 0; //连续和
        int maxAns = nums[0]; //最大连续和
        for (const auto &x: nums)
        {
            ans = max(ans + x, x);
            maxAns = max(maxAns, ans);
        }
        return maxAns;
    }*/



    /*分治法
    struct Status
    {
        int lSum, rSum, mSum, iSum;
        *//*lSum表示 [l,r] 内以 l为左端点的最大子段和;
        rSum表示 [l,r] 内以 r为右端点的最大子段和;
        mSum表示 [l,r] 内的最大子段和。
        iSum表示 [l,r] 这个区间的和。*//*

    };

    Status get(vector<int> &a, int left, int right)
    {
        if (left == right)
        {
            //2.治：返回当前数组四个子区间和
            return (Status) {a[left], a[left], a[left], a[left]};
        }
        //1.分：递归分割数组，直到不能再分为止
        int mid = (left + right) / 2;
        Status leftSub = get(a, left, mid);
        Status rightSub = get(a, mid + 1, right);

        //3.合：根据左右数组四个子区间和，维护当前整个数组的四个子区间和
        int iSum = leftSub.iSum + rightSub.iSum;
        int lSum = max(leftSub.lSum, leftSub.iSum + rightSub.lSum);
        int rSum = max(rightSub.rSum, rightSub.iSum + leftSub.rSum);
        int mSum = max(max(leftSub.mSum, rightSub.mSum), leftSub.rSum + rightSub.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    int maxSubArray1(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }*/

};
//leetcode submit region end(Prohibit modification and deletion)


