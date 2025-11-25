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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==NULL){
            return arr;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left!=NULL)s1.push(node->left);
            if(node->right!=NULL)s1.push(node->right);
        }
        while(!s2.empty()){
            arr.push_back(s2.top()->val);
            s2.pop();
        }
        return arr;
    }
};