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
        int d=0;
        while(root!=NULL){
            root=root->left;
            d++;
        }
        return d;
    }

    int countright(TreeNode* root){
        int d=0;
        while(root!=NULL){
            root=root->right;
            d++;
        }
        return d;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = countleft(root);
        int right = countright(root);

        if(left==right)return((1<<left)-1);

        return(1+countNodes(root->left)+countNodes(root->right));
    }
};