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

    TreeNode* getleftright(TreeNode* root){
        TreeNode* leaf = NULL;
        while(root!=NULL){
            leaf = root;
            root=root->right;
        }
        return leaf;
    }

    TreeNode* delnode(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* right = root->right;
        TreeNode* left = root->left;

        TreeNode* leftright = getleftright(left);

        leftright->right = right;
        return left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return delnode(root);
        }
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->val>key){
                if(curr->left!=NULL&&curr->left->val==key){
                    curr->left = delnode(curr->left);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right!=NULL&&curr->right->val==key){
                    curr->right = delnode(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};