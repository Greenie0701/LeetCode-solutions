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
    void linkparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
                m[node->left] = node;
            }
            if(node->right!=NULL){
                q.push(node->right);
                m[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> arr;
        if(root==NULL){
            return arr;
        }
        unordered_map<TreeNode*, TreeNode*> m;
        linkparent(root, m);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        int dist = 0;
        while(!q.empty()){
            if(dist==k)break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL&&!visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }

                if(node->right!=NULL&&!visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }

                if(m[node]!=NULL&&!visited[m[node]]){
                    q.push(m[node]);
                    visited[m[node]]=true;
                }
            }
            dist++;
        }
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            arr.push_back(node->val);
        }
        return arr;
    }
};