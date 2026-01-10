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
    
    void dfs(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int targetSum){
        if(!root)return;
        path.push_back(root->val);
        if(root&&!root->left&&!root->right){
            if(root->val==targetSum){
                result.push_back(path);
            }
        }
        else{
            dfs(result, path, root->left, targetSum-root->val);
            dfs(result, path, root->right, targetSum-root->val);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, root, targetSum);
        return result;
    }
};