//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 数组 回溯 👍 1454 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }

    void backtracking(vector<int> &nums, vector<bool> used)
    {
        //1.到达结尾，返回
        if (nums.size() == path.size())
        {
            result.push_back(path);
            return;
        }
        //2.递归遍历
        for (int i = 0; i < nums.size(); ++i)
        {
            //数组元素和前面元素相同，前面元素在上层用过，就跳过
            /*例如对于[1,1,2]来说，其实排除的组合是[第一个1，第二个1，2]，
             * 保留了最后一个重复的结果[第二个1, 第一个1, 2]*/
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1]==false)
                continue;
            //数组元素在上层中用过了，下层中就不能用
            if (used[i])
                continue;
            used[i] = true; //标记用过了
            path.push_back(nums[i]);
            backtracking(nums, used);
            //3.回溯
            path.pop_back();
            used[i] = false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
