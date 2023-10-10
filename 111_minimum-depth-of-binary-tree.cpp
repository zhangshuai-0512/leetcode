//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 10⁵] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1031 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution
{
public:
    int minDepth(TreeNode *root)
    {//***递归法首先要给出递归结束的条件
        //节点为空，则深度为0
        if(root== nullptr)
            return 0;
        if(root->left== nullptr && root->right== nullptr)
            return 1;
        //1.节点的左右节点有一个为空，则深度为非空子节点的子树深度+1
        if(root->left== nullptr && root->right!= nullptr)
        {
            return minDepth(root->right)+1;
        }
        if(root->left!= nullptr && root->right== nullptr)
        {
            return minDepth(root->left)+1;
        }
        //2.如果两个子节点都不为空，则继续递归两个子节点
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {   //根节点为空，最小深度为0
        if(root== nullptr)
        {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int depth=1;
        //层序遍历
        while(!que.empty())
        {
            int que_size=que.size();
            for (int i = 0; i < que_size; i++)
            {
                TreeNode* node =que.front();
                que.pop();
                //两子节点都为空，满足条件，返回最小深度
                if(node->left== nullptr && node->right== nullptr)
                {
                    return depth;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }//没遍历完一层，高度加1
            depth+=1;
        }
        return depth;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
