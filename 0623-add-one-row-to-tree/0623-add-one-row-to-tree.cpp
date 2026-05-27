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
    void dfs(TreeNode* root, int val, int curr, int depth){
        if(!root)return;
        if(curr==depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return;
        }
        dfs(root->left, val, curr+1, depth);
        dfs(root->right, val , curr+1, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root, val, 1, depth);
        return root;
    }
};