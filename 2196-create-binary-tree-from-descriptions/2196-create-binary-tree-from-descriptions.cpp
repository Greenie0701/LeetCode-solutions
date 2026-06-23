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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> children;
        for(vector<int>& v:descriptions){
            int parent = v[0];
            int child = v[1];
            int isleft = v[2];
            if(m.find(parent)==m.end()){
                m[parent] = new TreeNode(parent);
            }
            if(m.find(child)==m.end()){
                m[child] = new TreeNode(child);
            }
            if(isleft){
                m[parent]->left=m[child];
            }
            else{
                m[parent]->right=m[child];
            }
            children.insert(child);
        }
        for(auto& it:m){
            if(children.find(it.first)==children.end())return it.second;
        }
        return NULL;
    }
};