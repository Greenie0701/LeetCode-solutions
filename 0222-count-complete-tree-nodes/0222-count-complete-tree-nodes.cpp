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

    int countleft(TreeNode* root){
        int c=0;
        while(root!=NULL){
            c++;
            root=root->left;
        }
        return c;
    }

    int countright(TreeNode* root){
        int c=0;
        while(root!=NULL){
            c++;
            root=root->right;
        }
        return c;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int leftnodes = countleft(root);
        int rightnodes = countright(root);

        if(rightnodes==leftnodes)return((1<<leftnodes)-1);

        return(1+countNodes(root->left)+countNodes(root->right));
    }
};