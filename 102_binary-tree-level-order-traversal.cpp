//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 1525 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

  //Definition for a binary tree node.
 /*struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(!root)
        {
            vector<vector<int>> r;
            return r;
        }
        if(!root->left && !root->right)
        {
            vector<vector<int>> r= {{root->val}};
            return r;
        }

        queue<TreeNode *> qu;
        qu.push(root);

        vector<vector<int>> r;
        r.push_back({root->val});

        while(!qu.empty())
        {
            int len=qu.size();
            vector<int> mid;
            for(int i=0;i<len;i++)
            {
                TreeNode *node=qu.front();
                qu.pop();

                if(node->left )
                {
                    qu.push(node->left);
                    mid.push_back(node->left->val);
                }
                if(node->right )
                {
                    qu.push(node->right);
                    mid.push_back(node->right->val);
                }
            }
            if(!mid.empty())
            {
                r.push_back(mid);
            }

            mid.clear();
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
