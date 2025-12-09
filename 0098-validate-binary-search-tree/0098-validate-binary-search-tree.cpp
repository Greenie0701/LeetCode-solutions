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
    bool ValidBST(TreeNode* root, long long minval, long long maxval) {
        if(root==NULL){
            return true;
        }
        if(root->val<=minval||root->val>=maxval)return false;

        return(ValidBST(root->left,minval, root->val)&&ValidBST(root->right, root->val, maxval));
    }
    bool isValidBST(TreeNode* root) {
        return ValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};