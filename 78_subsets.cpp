//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
//
// Related Topics 位运算 数组 回溯 👍 2138 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.push_back({});
        backtracking(nums,0);
        return result;
    }
    void backtracking(vector<int> &nums, int startindex)
    {
        //1.到达结尾，返回
        if(startindex>=nums.size())
            return;
        //2.递归遍历
        for (int i = startindex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            result.push_back(path);  //每个组合都是一个结果
            backtracking(nums, i+1);
            //3.回溯
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
