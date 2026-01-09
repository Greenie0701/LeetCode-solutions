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
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            unsigned long long size = q.size();
            unsigned long long min_index = q.front().second;
            unsigned long long first = 0;
            unsigned long long last = 0;
            for(int i=0; i<size; i++){
                auto val = q.front();
                TreeNode* node = q.front().first;
                q.pop();
                unsigned long long curr = val.second-min_index;
                if(i==0)first=curr;
                if(i==size-1)last=curr;
                if(node->left){
                    q.push({node->left, 2*(curr)+1});
                }
                if(node->right){
                    q.push({node->right, 2*(curr)+2});
                }
            }
            width = max(width, last - first + 1);
        }
        return int(width);
    }
};