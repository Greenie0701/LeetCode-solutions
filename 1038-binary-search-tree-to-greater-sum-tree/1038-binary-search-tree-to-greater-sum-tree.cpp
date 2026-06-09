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
    void dfs(TreeNode* root, int& node_sum){
        if(!root)return;
        dfs(root->right, node_sum);
        node_sum+=root->val;
        root->val = node_sum;
        dfs(root->left, node_sum);
    }


    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};