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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long width = 0;
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int first = 0; 
        int last = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned long long minindex = q.front().second;
            for(int i=0; i<size; i++){
                auto node = q.front();
                q.pop();
                unsigned long long curr = node.second - minindex;
                if(i==0)first = curr;
                if(i==size-1)last = curr;
                if(node.first->left!=NULL)q.push({node.first->left, 2*curr+1});
                if(node.first->right!=NULL)q.push({node.first->right, 2*curr+2});
            }
            width = max(int(width), int(last-first+1));
        }
        return int(width);
    }
};