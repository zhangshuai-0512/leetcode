//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。 
//
// 题目数据保证答案符合 32 位带符号整数范围。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//rabbbit
//rabbbit
//rabbbit 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 1034 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int slen = s.length();
        int tlen = t.length();
        if (slen < tlen)
            return 0;

        vector<vector<uint64_t>> dp(slen + 1, vector<uint64_t>(tlen + 1, 0));
        for (int i = 0; i < slen; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= slen; ++i)
        {
            for (int j = 1; j <= tlen; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[slen][tlen];
    }



/*  记忆化递归搜索
    vector<vector<int> > dp; //使用dp[i][j]数组存储s前i个字符匹配到t前j个字符的种数
    int numDistinct2(string s, string t)
    {
        dp.assign(s.length(), vector<int>(t.length(), -1));
        return dfs(s, t, s.length() - 1, t.length() - 1);  //从后向前匹配
    }

    int dfs(string &s, string &t, int i, int j)
    {
        if (j < 0) //如果t字符串超出边界，说明t字符串匹配完成
        {
            return 1;
        }
        //如果t字符串还没超出边界，而s字符串到达边界，说明没有匹配成功
        if (i < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1) //如果dp数组有记录，直接返回
        {
            return dp[i][j];
        }
        //当s[i]与t[j]相匹配，可以选择或者不选择s[i]去匹配t[j];
        //（1）如果选择匹配，再看s[i]前面是否还能匹配t[j]前面，就是dfs(s, t, i-1, j-1)
        //（2）如果选择不匹配，再看s[i]前面是否还能匹配t[j]，就是dfs(s, t, i-1, j)
        if (s[i] == t[j])
        {
            dp[i][j] = dfs(s, t, i - 1, j) + dfs(s, t, i - 1, j - 1);
        }
            //当s[i]与t[j]不匹配，只能寻找s[i]前面的字符去匹配t[j];
        else
        {
            dp[i][j] = dfs(s, t, i - 1, j);
        }
        return dp[i][j];
    }*/
};





