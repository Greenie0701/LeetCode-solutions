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
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, 
    queue<pair<TreeNode*, int>>& q, int val, unordered_set<TreeNode*>& visited){
        if(!root)return;
        if(root->val==val){
            q.push({root, 0});
            visited.insert(root);
        }
        if(root->left){
            parent[root->left]=root;
            dfs(root->left, parent, q, val, visited);
        }
        if(root->right){
            parent[root->right]=root;
            dfs(root->right, parent, q, val, visited);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        dfs(root, parent, q, start, visited);
        int result = 0;
        while(!q.empty()){
            int size = q.size();
            result = max(result, q.front().second);
            for(int i=0; i<size; i++){
                auto[node, time] = q.front();
                q.pop();
                if(node->left&&visited.find(node->left)==visited.end()){
                    q.push({node->left, time+1});
                    visited.insert(node->left);
                }
                if(node->right&&visited.find(node->right)==visited.end()){
                    q.push({node->right, time+1});
                    visited.insert(node->right);
                }
                if(parent[node]&&visited.find(parent[node])==visited.end()){
                    q.push({parent[node], time+1});
                    visited.insert(parent[node]);
                }
            }
        }
        return result;
    }
};