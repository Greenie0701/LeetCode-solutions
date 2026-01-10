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
    void dfs(TreeNode* root, int& sum, int left){
        if(!root)return;

        if(!root->left&&!root->right&&left){
            sum+=root->val;
        }
        else{
            dfs(root->left, sum, 1);
            dfs(root->right, sum, 0);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root, sum, 0);
        return sum;
    }
};