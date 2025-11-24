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
    void dfs(vector<int>& arr, TreeNode* node){
        if(node==NULL){
            return;
        }
        arr.push_back(node->val);
        dfs(arr, node->left);
        dfs(arr, node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        dfs(preorder, root);
        return preorder;
    }
};