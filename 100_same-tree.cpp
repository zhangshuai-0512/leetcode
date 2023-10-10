//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。 
//
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。 
//
// 
//
// 示例 1： 
// 
// 
//输入：p = [1,2,3], q = [1,2,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：p = [1,2], q = [1,null,2]
//输出：false
// 
//
// 示例 3： 
// 
// 
//输入：p = [1,2,1], q = [1,1,2]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 两棵树上的节点数目都在范围 [0, 100] 内 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 933 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
/* struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        queue<TreeNode*> que;
        que.push(p);   //  添加根节点p
        que.push(q);  //  添加根节点q
        while (!que.empty()) {
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {  // 若p的节点与q的节点都为空
                continue;
            }
            // 若p的节点与q的节点有一个为空或p的节点的值与q节点不同
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            que.push(leftNode->left);   // 添加p节点的左子树节点
            que.push(rightNode->left); // 添加q节点的左子树节点
            que.push(leftNode->right);  // 添加p节点的右子树节点
            que.push(rightNode->right);  // 添加q节点的右子树节点
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/*
int main()
{
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t1=new TreeNode(1,t2,t3);

    TreeNode *t5=new TreeNode(2);
    TreeNode *t6=new TreeNode(3);
    TreeNode *t4=new TreeNode(1,t5,t6);
    Solution *s=new Solution();
    cout<<s->isSameTree(t1,t4);
}*/
