//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 10⁴ 
// s[i] 为 '(' 或 ')' 
// 
//
// Related Topics 栈 字符串 动态规划 👍 2281 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int longestValidParentheses2(string s)
    {
        stack<int> st;  //存储字符串索引
        st.push(-1); //作为参考物
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {   //如果是左括号，则入栈
            if (s[i] == '(')
            {
                st.push(i);
            } else
            {//如果是右括号，则栈顶元素出栈；
                st.pop();
                //出栈元素可能是'('的索引，也可能是'-1'；
                //如果是-1，则栈空，此时需要将右括号入栈作为参考物，如果下一个字符任然是右括号，则此右括号出栈，下一个入栈；
                //这个无法匹配的有括号和'-1'一样，是下一组有效括号的起始位置，用以计算有效括号长度
                if (st.empty())
                {
                    st.push(i);
                }
                    //如果栈未空，则说明出栈元素为左括号，此时计算并比较一下最大有效长度
                else
                {
                    maxLen = max(i - st.top(), maxLen);
                }
            }
        }
        return maxLen;
    }

    int longestValidParentheses(string s)
    {
        int maxLen = 0;
        int len = s.length();
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    if (i - 2 >= 0)
                    {
                        dp[i] = dp[i - 2] + 2;
                    } else
                    {
                        dp[i] = 2;
                    }
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0)
                    {
                        dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                    } else
                    {
                        dp[i] = dp[i - 1] + 2;
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
