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

    int long_path = 0;

    void dfs(TreeNode* root, bool left, int step){
        if(!root)return;
        long_path = max(long_path, step);
        if(left){
            dfs(root->right, 1, 1);
            dfs(root->left, 0, step+1);
        }
        else{
            dfs(root->left, 0, 1);
            dfs(root->right, 1, step+1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 1, 0);
        return long_path;
    }
};