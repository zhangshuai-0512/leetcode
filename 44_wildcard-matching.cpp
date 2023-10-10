//
// 给你一个输入字符串 (
// s) 和一个字符模式 (
// p) ，请你实现一个支持 
// '?' 和 
// '*' 匹配规则的通配符匹配：
// 
//
// 
// '?' 可以匹配任何单个字符。 
// '*' 可以匹配任意字符序列（包括空字符序列）。 
// 
//
// 
// 
// 判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aa", p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2： 
//
// 
//输入：s = "aa", p = "*"
//输出：true
//解释：'*' 可以匹配任意字符串。
// 
//
// 示例 3： 
//
// 
//输入：s = "cb", p = "?a"
//输出：false
//解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= slength, plength <= 2000
// s 仅由小写英文字母组成 
// p 仅由小写英文字母、'?' 或 '*' 组成 
// 
//
// Related Topics 贪心 递归 字符串 动态规划 👍 1048 👎 0

#include<bits/stdc++h>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_len = s.length();
        int p_len = p.length();
        int i = 0;
        int j = 0;
        int start = -1;
        int match = 0;
        //逐个字符匹配
        while (i < s_len)
        {   //如果匹配到'?'或者两字符相同，继续匹配下一个字符
            if (j < p_len && (s[i] == p[j] || p[j] == '?'))
            {
                i++;
                j++;
            }
            //如果匹配到'*',记录位置
            else if (j < p_len && p[j] == '*')
            {
                start = j;
                match = i;
                j++;
            }
            //继续看p字符串后面的字符能否匹配到s后面的字符
            else if (start != -1)
            {
                j = start + 1;
                match++;
                i = match;
            } else
            {
                return false;
            }
        }
        //若p字符串未能完全匹配，未匹配的字符串不是全'*'，返回false
        while (j < p_len)
        {
            if (p[j] != '*') return false;
            j++;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
