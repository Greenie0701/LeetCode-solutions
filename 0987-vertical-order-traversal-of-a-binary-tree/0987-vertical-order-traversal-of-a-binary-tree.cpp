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
        vector<vector<int>> result;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        map<int, map<int, multiset<int>>> m;
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int x = val.first.first;
            int y = val.first.second;
            TreeNode* node = val.second;
            m[x][y].insert(node->val);
            if(node->left){
                q.push({{x-1, y+1}, node->left});
            }
            if(node->right){
                q.push({{x+1, y+1},node->right});
            }
        }
        for(auto pointer:m){
            vector<int> level;
            for(auto pointer:pointer.second){
                level.insert(level.end(), pointer.second.begin(), pointer.second.end());
            }
            result.push_back(level);
        }
        return result;
    }
};