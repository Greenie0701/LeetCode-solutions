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

    void recover(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& last){
        if(root==NULL){
            return;
        }
        recover(root->left, prev, first, last);

        if(prev!=NULL&&root->val<prev->val){
            if(first==NULL){
                first = prev;
                last = root;
            }
            else{
                last = root;
            }
        }

        prev = root;

        recover(root->right, prev, first, last);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *curr = root, *prev =NULL, *first= NULL, *last=NULL;
        recover(root, prev, first, last);
        swap(first->val, last->val);
    }
};