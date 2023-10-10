//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。 
//
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表
//示如果要学习课程 ai 则 必须 先学习课程 bi 。 
//
// 
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。 
// 
//
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。 
//
// 示例 2： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。 
//
// 
//
// 提示： 
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// prerequisites[i] 中的所有课程对 互不相同 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 1676 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for (int i = 0; i < prerequisites.size(); ++i)
        {//初始化入度数组 和 邻接表
            int preNode=prerequisites[i][1];
            int nextNode=prerequisites[i][0];
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
            return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
