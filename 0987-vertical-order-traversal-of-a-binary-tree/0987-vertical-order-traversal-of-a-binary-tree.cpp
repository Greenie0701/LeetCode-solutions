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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==NULL){
            return arr;
        }
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root, {0,0}});
        map<int, map<int, multiset<int>>> m;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.second.first;
            int y = node.second.second;
            m[x][y].insert(node.first->val);
            if(node.first->left!=NULL)q.push({node.first->left,{x-1, y+1}});
            if(node.first->right!=NULL)q.push({node.first->right,{x+1, y+1}});
        }
        for(auto point:m){
            vector<int> line;
            for(auto p:point.second){
                line.insert(line.end(), p.second.begin(), p.second.end());
            }
            arr.push_back(line);
        }
        return arr;
    }
};