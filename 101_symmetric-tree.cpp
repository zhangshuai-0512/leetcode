//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2461 👎 0

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
/*
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> que; //用队列层序遍历树
        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {//拿出两个节点
            TreeNode *left_node = que.front();
            que.pop();
            TreeNode *right_node = que.front();
            que.pop();
            //两节点都为空，则跳过
            if (!left_node && !right_node)
                continue;
            //对应镜像两节点有一个为空，或者数值不相等，即不对称
            if(!left_node || !right_node || (left_node->val!=right_node->val))
                return false;

            //将左右分支的对应节点加入队列
            que.push(left_node->left);  //左分支的左节点
            que.push(right_node->right); //右分支的右节点

            que.push(left_node->right);  //左分支的右节点
            que.push(right_node->left);  //右分支的左节点
        }
        return true;
    }
};
*/

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
            // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
        bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
