//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 👍 2772 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string s="";
        int left=0;
        int right=0;
        backTrack(result,s,0,0,n);
        return result;
    }
    void backTrack(vector<string>& ans,string& cur,int open,int close,const int& n)
    {
        if(cur.size()==2*n)
        {
            ans.push_back(cur);
            return;
        }
        if(open<n)
        {
            cur.push_back('(');
            backTrack(ans,cur,open+1,close,n);
            cur.pop_back();
        }
        if(close<open)
        {
            cur.push_back(')');
            backTrack(ans,cur,open,close+1,n);
            cur.pop_back();
        }



    }
};
//leetcode submit region end(Prohibit modification and deletion)
