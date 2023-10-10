//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1355 👎 0

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
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root)==-1? false:true;
    }
    // 后序递归遍历（左中右），返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
    int getHeight(TreeNode* root)
    {   //节点为空，高度为0
        if(!root)
            return 0;
        //1.先遍递归历左节点，求其高度
        int leftHeight= getHeight(root->left);
        //判断左节子树是否为平衡二叉树
        if(leftHeight==-1)
            return -1;
        //2.再遍递归历右节点，求其高度
        int rightHeight= getHeight(root->right);
        //判断右节子树是否为平衡二叉树
        if(rightHeight==-1)
            return -1;
        //3.判断根节点左右树高度差，是否为平衡二叉树
        if(abs(leftHeight-rightHeight)>1)
            return -1;
        //返回根节点最大高度
        else
            return max(leftHeight,rightHeight)+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
