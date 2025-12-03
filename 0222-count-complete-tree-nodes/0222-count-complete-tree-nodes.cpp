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

    int totalnodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftnodes = findleftnodes(root);
        int rightnodes = findrightnodes(root);
        if(leftnodes==rightnodes)return((1<<(leftnodes))-1);
        return(1+totalnodes(root->left)+totalnodes(root->right));
    }

    int findleftnodes(TreeNode* root){
        int d=0;
        while(root!=NULL){
            d++;
            root=root->left;
        }
        return d;
    }

    int findrightnodes(TreeNode* root){
        int d=0;
        while(root!=NULL){
            d++;
            root=root->right;
        }
        return d;
    }

    int countNodes(TreeNode* root) {
        return totalnodes(root);
    }
};