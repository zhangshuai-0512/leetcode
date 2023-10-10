//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics 回溯 👍 1486 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int maxDepth; //组合要求的数量，也就是树的最大深度
    vector<int> path; //存储可能的一个组合
    vector<vector<int>> result; //存储所有组合结果

    vector<vector<int>> combine(int n, int k)
    {
        maxDepth = k;
        backtracking(1, n);
        return result;
    }

    void backtracking(int start, int end)
    {   //1.组合内数字个数满足条件，递归结束
        if (path.size() == maxDepth)
        {
            result.push_back(path);
            return;
        }
        //2.遍历递归
        for (int i = start; i <= end +1 - (maxDepth - path.size()); i++)
        {
            path.push_back(i);
            backtracking(i + 1, end);
            //3.回溯
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
