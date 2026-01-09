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

    void linkparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        linkparent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target]=true;
        int dist = 0;
        while(!q.empty()){
            if(dist==k)break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(parent[node]!=NULL&&!visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }

                if(node->left&&!visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }

                if(node->right&&!visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }
            }
            dist++;
        }

        vector<int> arr;

        while(!q.empty()){
            arr.push_back(q.front()->val);
            q.pop();
        }

        return arr;
    }
};