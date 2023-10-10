//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2013 👎 0

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
class Solution {
public:
    unordered_map<int, int> mp; //存储inorder值的索引
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int length=inorder.size();
        for (int i = 0; i < length; ++i)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=new TreeNode(preorder[0]); //根节点
        helper(root,preorder,inorder,0,length-1,0,length-1);
        return root;
    }

    void helper(TreeNode *root,vector<int> &preorder, vector<int> &inorder, int in_start, int in_end,int p_start,int p_end)
    {
        //如果p_start == p_end，即当前节点为叶子节点，返回
        if (p_start == p_end)
        {
            return;
        }
        //1.查找map，找到根节点在中序数组中的位置，然后找到左节点和右节点
        int mid_index=mp[preorder[p_start]]; //注意这里不能是0，因为分片后起始位置会变化
        TreeNode *leftNode;
        TreeNode *rightNode;
        //左节点若存在，即in_start!=mid_index，将左节点连接
        if(in_start!=mid_index )
        {
            leftNode=new TreeNode(preorder[p_start+1]);
            root->left=leftNode;
        }
        //右节点若存在，即in_end!=mid_index，将右节点连接
        if(in_end!=mid_index)
        {
            rightNode = new TreeNode(preorder[p_end-in_end+mid_index+1]);
            root->right = rightNode;
        }
        /*2.分片继续迭代左子树
        int in_left=in_start; //左子树inorder起始
        int in_right=mid_index-1; //左子树inorder结尾
        int p_left=p_start; //左子树preorder起始
        int p_right=p_start+mid_index-in_start-1;//左子树preorder结尾
         */
        if(in_start!=mid_index)
            helper(leftNode,preorder,inorder,in_start,mid_index-1,p_start+1,p_start+mid_index-in_start);
        /*3.分片继续迭代右子树
         in_left=mid_index+1;
         in_right=in_end;
         p_left=p_end-in_end+mid_index;
         p_right=p_end-1;*/
        if(in_end!=mid_index)
            helper(rightNode,preorder,inorder,mid_index+1,in_end,p_end-in_end+mid_index+1,p_end);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
