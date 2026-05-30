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
        unsigned long long width=0;
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            unsigned long long first, last;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto[index, node] = q.front();
                q.pop();
                if(i==0)first=index;
                if(i==size-1)last=index;
                if(node->left)q.push({2*(index)+1, node->left});
                if(node->right)q.push({2*(index)+2, node->right});
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};