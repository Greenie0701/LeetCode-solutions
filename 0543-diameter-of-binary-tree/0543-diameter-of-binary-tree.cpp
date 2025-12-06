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

    int find(TreeNode* root, int& d){
        if(root==NULL){
            return 0;
        }
        int lh = find(root->left, d);
        int rh = find(root->right, d);

        d = max(d, rh+lh);
        return 1+max(rh, lh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        find(root, d);
        return d;
    }
};