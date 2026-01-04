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
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& result, int targetSum){
        if(!root){
            return;
        }
        path.push_back(root->val);
        if((!root->left&&!root->right)&&targetSum-root->val==0){
            result.push_back(path);
        }else{
            dfs(root->left, path, result, targetSum-root->val);
            dfs(root->right, path, result, targetSum-root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result, targetSum);
        return result;
    }
};