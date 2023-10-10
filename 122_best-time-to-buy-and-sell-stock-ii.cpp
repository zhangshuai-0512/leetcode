//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。 
//
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。 
//
// 返回 你能获得的 最大 利润 。 
//
// 
//
// 示例 1： 
//
// 
//输入：prices = [7,1,5,3,6,4]
//输出：7
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
//     总利润为 4 + 3 = 7 。 
//
// 示例 2： 
//
// 
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//     总利润为 4 。 
//
// 示例 3： 
//
// 
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 3 * 10⁴ 
// 0 <= prices[i] <= 10⁴ 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2240 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    //动态规划
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0]; //第0天持有股票利润，即买了股票后的利润
        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); //第i天持有股票获得的利润
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); //第i天不持有股票获得的利润
        }
        return dp[prices.size() - 1][1];
    }

    /*直接在上涨段，每天都低买高卖，不用一次性找出波峰波谷
   int maxProfit(vector<int> &prices)
   {
       int result = 0;
       for (int i = 1; i < prices.size(); i++)
       {
           result += max(prices[i] - prices[i - 1], 0);
       }
       return result;
   }*/



    /*int maxProfit(vector<int> &prices)
    {
        int minpri = 0; //记录波谷位置
        int maxpri = 0; //记录波峰位置
        int result = 0;//记录结果
        int i = 1;
        while (i < prices.size())
        {
            //1.先找到波谷位置
            while (i < prices.size() && prices[i - 1] >= prices[i])
            {
                minpri = i;
                i++;
            }
            //2.找到波峰位置
            while (i < prices.size() && prices[i - 1] <= prices[i])
            {
                maxpri = i;
                i++;
            }
            //3.如果波峰在波谷后面，那么就可以低买高卖
            if (maxpri >= minpri)
                result += prices[maxpri] - prices[minpri];
        }
        return result;
    }*/



};
//leetcode submit region end(Prohibit modification and deletion)
