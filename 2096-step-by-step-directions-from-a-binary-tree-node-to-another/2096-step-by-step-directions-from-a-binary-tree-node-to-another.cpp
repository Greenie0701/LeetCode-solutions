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
    bool findpath(TreeNode* root, int& val, string& path){
        if(!root)return false;
        if(root->val==val)return true;
        path.push_back('L');
        if(findpath(root->left, val, path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findpath(root->right, val, path)){
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start, end;
        findpath(root, startValue, start);
        findpath(root, destValue, end);
        int i=0;
        while(i<start.length()&&i<end.length()&&start[i]==end[i])i++;
        string result;
        result.append(start.length()-i, 'U');
        result.append(end.substr(i));
        return result;
    }
};