//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上
//被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 2： 
//
// 
//输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
//
// Related Topics 数组 动态规划 👍 2779 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        //1.dp[i]：下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
        vector<int> dp(nums.size()+1,0);
        //2.初始化：
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        //3.递推公式 dp[i]=max(dp[i-2]+nums[i-1], dp[i-1]);
        /*不偷房间i，就可以偷房间i-1，即dp[i]取决于dp[i-1]
         *  偷房间i，就只能偷房间i-2，即dp[i]取决于dp[i-2]+nums[i-1]
         *  nums[i-1]表示房间i
         */
        for (int i = 3; i <= nums.size(); ++i)
        {
            dp[i]=max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[nums.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
