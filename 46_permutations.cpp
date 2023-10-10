//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
//
// Related Topics 数组 回溯 👍 2686 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }

    void backtracking(vector<int> &nums,vector<bool> used)
    {
        //1.到达结尾，返回
        if (nums.size()==path.size())
        {
            result.push_back(path);
            return;
        }
        //2.递归遍历
        for (int i = 0; i <nums.size(); ++i)
        {   //数组元素在上层中用过了，下层中就不能用
            if(used[i])
                continue;
            used[i]=true; //标记用过了
            path.push_back(nums[i]);
            backtracking(nums, used);
            //3.回溯
            path.pop_back();
            used[i]=false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
