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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int val = 0; 
        int count =0;
        while(curr!=NULL){
            if(curr->left==NULL){
                count++;
                if(count==k)val = curr->val;
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL&&prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    count++;
                    prev->right=NULL;
                    if(count==k)val = curr->val;
                    curr = curr->right;
                }
            }
        }
        return val;
    }
};