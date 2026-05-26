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
    void dfs(TreeNode* root, string& result){
        if(!root)return;

        result+=to_string(root->val);
        if(root->left){
            result+="(";
            dfs(root->left, result);
            result+=")";
        }
        if(root->right){
            if(!root->left)result+="()";
            result+="(";
            dfs(root->right, result);
            result+=")";
        }

    }
    string tree2str(TreeNode* root) {
        string result="";
        dfs(root, result);
        return result;
    }
};