//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ['1','1','1','1','0'],
//  ['1','1','0','1','0'],
//  ['1','1','0','0','0'],
//  ['0','0','0','0','0']
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ['1','1','0','0','0'],
//  ['1','1','0','0','0'],
//  ['0','0','1','0','0'],
//  ['0','0','0','1','1']
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2269 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int gridX;
    int gridY;
    vector<vector<char>> graph;
    vector<vector<bool>> visited; //记录节点是否已经被访问
    int numIslands(vector<vector<char>> &grid)
    {
        graph = grid;
        gridX = grid.size();
        gridY = grid[0].size();
        int landsNum = 0;
        visited=vector<vector<bool>>(gridX,vector<bool>(gridY,false));
        //遍历数组元素
        for (int i = 0; i < gridX; ++i)
        {
            for (int j = 0; j < gridY; ++j)
            {   //对于没有被访问的陆地，进行DFS，标记同一片岛屿的陆地
                if (!visited[i][j] && graph[i][j] == '1')
                {
                    dfs(i, j);
                    landsNum++; //遍历完一个岛屿，计数加一
                }
            }
        }
        return landsNum;
    }
    void dfs(int x, int y)
    {   //1.数组越界，遇到海洋，或者节点已经被访问，就返回
        if (x<0 || x >= gridX || y<0 || y >= gridY || graph[x][y] == '0' || visited[x][y])
        {
            return;
        }
        //2.标记节点，然后继续访问上下左右四个方向的邻节点
        visited[x][y]=true;
        dfs(x -1, y);
        dfs(x, y + 1);
        dfs(x+1, y);
        dfs(x, y - 1);
    }
};

//leetcode submit region end(Prohibit modification and deletion)