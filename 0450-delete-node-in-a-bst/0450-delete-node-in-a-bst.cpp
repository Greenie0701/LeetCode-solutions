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

    TreeNode* delnode(TreeNode* node){
        if(!node->right){
            return node->left;
        }
        if(!node->left){
            return node->right;
        }
        TreeNode* leftchild = node->left;
        TreeNode* rightchild = node->right;
        TreeNode* leftright = node->left;
        while(leftright->right){
            leftright = leftright->right;
        }
        leftright->right = rightchild;
        return leftchild;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // No valid binary tree
        if(!root){
            return NULL;
        }
        // If the root node is to be deleted
        if(root->val==key){
            return delnode(root);
        }
        // If root node is to be deleted, search the node to be deleted
        TreeNode* curr = root;
        while(curr){
            if(key>curr->val){
                if(curr->right&&curr->right->val == key){
                    curr->right = delnode(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                    
                }
            }
            else{
                if(curr->left&&curr->left->val==key){
                    curr->left = delnode(curr->left);
                    break;
                }
                else{
                    curr = curr->left;
                
                }
            }
        }
        // Return the root after deleting the node
        return root;
    }
};