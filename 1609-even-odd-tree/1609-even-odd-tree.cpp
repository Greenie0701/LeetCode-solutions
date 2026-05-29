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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            int size = q.size();
            int level = q.front().first;
            bool even = level%2==0;
            int prev = even?INT_MIN:INT_MAX;
            for(int i=0; i<size; i++){
                auto[l, node] = q.front();
                q.pop();
                if(even){
                    if(node->val%2==0)return false;
                    if(node->val<=prev)return false;
                }
                else{
                    if(node->val%2!=0)return false;
                    if(node->val>=prev)return false;
                }
                prev = node->val;
                if(node->left)q.push({level+1, node->left});
                if(node->right)q.push({level+1, node->right});
            }
        }
        return true;
    }
};