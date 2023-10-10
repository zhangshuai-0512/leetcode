//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1620 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:
    vector<vector<string>> result;
    vector<string> path; // 存储回文子串
    void backtracking(const string &s, int startIndex)
    {
        //1.如果起始位置已经大于s的大小，说明已经找到了一组分割方案了，存储返回
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        //2.递归寻找回文串，每次截取长为i的子串，判断是回文子串存储；不是回文继续向后遍历
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
                continue;
            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            //3.回溯过程，弹出本次已经添加的子串
            path.pop_back();
        }

    }
    //判断字符串是否为回文串
    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
