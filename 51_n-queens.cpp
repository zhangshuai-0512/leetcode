//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 
//
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
//
// Related Topics 数组 回溯 👍 1891 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> result; //存储所有结果
    vector<string> path; //存储其中一个结果
    //标记棋盘某一个位置行列，撇捺对角线，是否已经有棋子了
    vector<bool> row;
    vector<bool> colume;
    vector<bool> ldiagonal;//撇：同一对角线行和列之差相等，为了防止负数，整体加n-1
    vector<bool> rdiagonal; //捺：同一对角线行和列之和相等
    vector<vector<string>> solveNQueens(int n)
    {
        row=vector<bool>(n,false);
        colume=vector<bool>(n,false);
        ldiagonal=vector<bool>(2*n-1,false);
        rdiagonal=vector<bool>(2*n-1,false);
        backtracking(n,0);
        return result;
    }

    void backtracking(int n, int line)
    {
        //1.到达结尾，获得一个结果，返回
        if (path.size()==n)
        {
            result.push_back(path);
            return;
        }

        //2.按行递归遍历
        for (int i = 0; i <n; ++i)
        {   //判断行line，列i这个位置是否能走，不能走就跳过剪枝
            if(row[line] || colume[i] || ldiagonal[line-i+n-1] || rdiagonal[line+i])
                continue;
            //位置能走，存储这一步，并标记
            vector<char> tmp(n,'.');
            tmp[i]='Q';
            string str(tmp.begin(),tmp.end());
            path.push_back(str);
            row[line] =true;
            colume[i] =true;
            ldiagonal[line-i+n-1] =true;
            rdiagonal[line+i]=true;
            backtracking(n,line+1); //递归遍历下一行
            //3.回溯，清除标记
            path.pop_back();
            row[line] =false;
            colume[i] =false;
            ldiagonal[line-i+n-1] =false;
            rdiagonal[line+i]=false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
