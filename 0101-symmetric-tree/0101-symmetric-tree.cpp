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
    bool checksym(TreeNode* left, TreeNode* right){
        if(left==NULL||right==NULL){
            return left==right;
        }
        if(left->val!=right->val)return false;

        return(checksym(left->left, right->right)&&checksym(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) {
        return(root==NULL||checksym(root->left, root->right));
    }
};