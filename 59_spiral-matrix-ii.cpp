//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1055 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v(n,vector<int>(n,0));
        int start=0; //每层遍历开始的地方
        int mid=n/2; //矩阵的中心节点位置，n为奇数时有中心节点
        int loop=n/2; //层数，n为奇数时有n/2层和一个中心节点；n为偶数时有n/2层
        int count=1; //填入矩阵的元素
        while(loop--)
        {
            for (int j = start; j <n-start-1 ; j++)
            {
                v[start][j]=count++;
            }
            for (int i = start; i < n-start-1; i++)
            {
                v[i][n-1-start]=count++;
            }
            for (int j = n-start-1; j >start ; j--)
            {
                v[n-1-start][j]=count++;
            }
            for (int i = n-start-1; i > start; i--)
            {
                v[i][start]=count++;
            }
            //每次遍历一层改变起始节点位置
            start++;
        }
        //为中心节点赋值
        if(n%2==1)
        {
            v[mid][mid]=count;
        }
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution s=Solution();
    s.generateMatrix(4);
}