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

    TreeNode* getrightchild(TreeNode* node){
        TreeNode* prev = NULL;
        while(node!=NULL){
            prev = node;
            node = node->right;
        }
        return prev;
    }
    
    TreeNode* delnode(TreeNode* node){
        if(node->left==NULL){
            return node->right;
        }
        if(node->right==NULL){
            return node->left;
        }
        TreeNode* rightchild = node->right;
        TreeNode* leftchild = node->left;
        TreeNode* leftrightchild = getrightchild(leftchild);

        leftrightchild->right = rightchild;
        return leftchild;
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