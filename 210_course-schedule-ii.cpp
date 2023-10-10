//现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 
//prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。 
//
// 
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。 
// 
//
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：[0,1]
//解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
// 
//
// 示例 2： 
//
// 
//输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//输出：[0,2,1,3]
//解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
//因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。 
//
// 示例 3： 
//
// 
//输入：numCourses = 1, prerequisites = []
//输出：[0]
// 
//
// 
//提示：
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= numCourses * (numCourses - 1) 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// ai != bi 
// 所有[ai, bi] 互不相同 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 802 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i)
        {//初始化入度数组 和 邻接表
            int preNode = prerequisites[i][1];
            int nextNode = prerequisites[i][0];
            adj[preNode].push_back(nextNode);
            indegree[nextNode]++;
        }
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {//统计入度为0的点，入队列
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> sortedNode; //存储入度为0的节点
        sortedNode.clear();

        while (!q.empty())
        {   //取出入度为0的节点
            int node = q.front();
            q.pop();
            sortedNode.push_back(node);
            for (int i = 0; i < adj[node].size(); ++i)
            {//遍历当前节点的邻居节点
                int neighborNode = adj[node][i];
                --indegree[neighborNode]; //邻居节点入度减一
                if (indegree[neighborNode] == 0)
                    q.push(neighborNode); //如果邻居节点入度为0，入队列
            }
        }
        //最后如果所有节点访问过了，那么不存在环路
        if (sortedNode.size() == numCourses)
            return sortedNode;
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)





