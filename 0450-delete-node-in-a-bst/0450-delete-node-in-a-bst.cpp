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
        TreeNode* prev = NULL;
        while(root!=NULL){
            prev = root;
            root = root->right;
        }
        return prev;
    }

    TreeNode* delnode(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* leftchild = root->left;
        TreeNode* rightchild = root->right;
        TreeNode* leftright = getleftright(leftchild);
        leftright->right = rightchild;
        return leftchild;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Given tree is empty
        if(root==NULL){
            return root;
        }
        TreeNode* curr = root;
        // Root is to be deleted
        if(root->val==key){
            return delnode(root);
        }
        // Traverse through the tree to find the val to be deleted
        while(curr!=NULL){
            // Key occurs in left subtree
            if(curr->val>key){
                if(curr->left!=NULL&&curr->left->val==key){
                    curr->left = delnode(curr->left);
                    break;
                }else{
                    curr = curr->left;
                }
            }
            // Else occurs in right subtree
            else{
                if(curr->right!=NULL&&curr->right->val==key){
                    curr->right = delnode(curr->right);
                    break;
                }else{
                    curr = curr->right;
                }
            }
        }
        return root; 
    }
};