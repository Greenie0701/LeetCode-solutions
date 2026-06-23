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
    int csort(vector<int>& arr){
        int size = arr.size();
        vector<pair<int, int>> vec;
        for(int i=0; i<size; i++){
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<bool> visited(size, false);
        int result = 0;
        for(int i=0; i<size; i++){
            if(visited[i]||vec[i].second==i)continue;
            int swap = 0;
            int j = i;
            while(!visited[j]&&j<size){
                visited[j]=true;
                j = vec[j].second;
                swap++;
            }
            result+=swap-1;
        }
        return result;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
            }
            result+=csort(level);
        }
        return result;
    }
};