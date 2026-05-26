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
    int ans = 0;

    void dfs(TreeNode* root, int maxi, int mini){
        if(!root)return;
        ans = max(ans, max(abs(root->val-maxi), abs(root->val-mini)));
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        dfs(root->left, maxi, mini);
        dfs(root->right, maxi, mini);
    }


    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};