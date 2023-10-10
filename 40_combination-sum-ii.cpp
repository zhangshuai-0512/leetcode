//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1440 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<int> candidates;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        this->candidates = candidates;
        sort(this->candidates.begin(),this->candidates.end()); //排序
        backtracking(target,0,0);
        return result;
    }

    void backtracking(int target, int cursum, int startindex)
    {
        //组合的和超出目标值，返回
        if (cursum > target)
            return;
        //1.满足条件，存储结果，返回
        if (target == cursum)
        {
            result.push_back(path);
            return;
        }

        for (int i = startindex; i < candidates.size()&& candidates[i]<=target; i++)
        {
            //去重关键：每一层遍历，如果前面相同的数字是否已经用过了，用过了就跳过
            //（前面的数指本层中索引>=startindex的数）
            if(i>startindex && candidates[i]==candidates[i-1])
                continue;
            //2.递归遍历
            path.push_back(candidates[i]);
            cursum += candidates[i];
            backtracking(target, cursum,i+1);
            //3.回溯
            cursum -= candidates[i];
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
