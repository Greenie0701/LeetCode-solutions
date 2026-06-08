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
    bool dfs(TreeNode* root, int& value, string& path){
        if(!root)return false;

        if(root->val==value)return true;

        path.push_back('L');
        if(dfs(root->left, value, path)){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(dfs(root->right, value, path)){
            return true;
        } 
        path.pop_back();  

        return false;     
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path;
        string desc_path;
        dfs(root, startValue, start_path);
        dfs(root, destValue, desc_path);
        int i=0;
        while(i<start_path.length()&&i<desc_path.length()&&start_path[i]==desc_path[i])i++;
        string result;
        result.append(start_path.length()-i, 'U');
        result+=desc_path.substr(i);
        return result;
    }
};