/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);               
            }
        }
        q.push(target);
        vector<int> result;
        int dist =0;
        while(!q.empty()){

            if(dist==k)break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left&&!visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right&&!visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node]&&!visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            dist++;
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};