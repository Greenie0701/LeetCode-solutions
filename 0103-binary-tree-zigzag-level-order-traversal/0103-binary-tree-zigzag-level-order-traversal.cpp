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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==NULL){
            return arr;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftright = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size,0);
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = leftright?i:size-i-1;
                level[index]=node->val;
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right); 
            }
            arr.push_back(level);
            leftright = !leftright;
        }
        return arr;
    }
};