//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
//
// Related Topics 数组 排序 👍 2098 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //1.按照区间起始位置从小到大排序
        auto cintervals=[](const vector<int> &a, const vector<int> &b)
        {
            if(a.front()==b.front())
                return a.back()<b.back();
            return a.front()<b.front();
        };
        sort(intervals.begin(),intervals.end(), cintervals);

        //2.将有交集的区间合并，注意边界重合也算相交
        vector<vector<int>> result;
        int start=intervals[0].front();
        int end=intervals[0].back();
        for (int i = 1; i < intervals.size(); ++i)
        {
            if(start<=intervals[i].front() && intervals[i].front()<=end && intervals[i].back()>end)
            {   //有相交部分，合并区间，只需要将结束位置设置为两个区间右边界的最大值即可
                end=intervals[i].back();
            }
            else if(intervals[i].back()>end)
            {   //无相交，说明前面的区间合并完成
                result.push_back({start,end});
                start=intervals[i].front();
                end=intervals[i].back();
            }
        }
        //最后一个合并的区间
        result.push_back({start,end});
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
