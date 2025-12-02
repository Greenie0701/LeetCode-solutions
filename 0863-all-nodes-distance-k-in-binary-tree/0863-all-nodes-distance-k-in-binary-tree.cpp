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
    void markparentnode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                    m[node->left]=node;
                }
                if(node->right!=NULL){
                    q.push(node->right);
                    m[node->right]=node;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        markparentnode(root, m); 
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target]=true;
        int dist = 0;
        while(!q.empty()){
            if(dist==k)break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL&&!visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right!=NULL&&!visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(m[curr]!=NULL&&!visited[m[curr]]){
                    q.push(m[curr]);
                    visited[m[curr]] = true;
                }
            }
            dist++;
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};