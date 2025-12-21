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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> arr;
        while(curr){
            if(!curr->left){
                arr.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* left = curr->left;
                while(left->right&&left->right!=curr){
                    left = left->right;
                }

                if(!left->right){
                    left->right = curr;
                    curr = curr->left;
                }
                else{
                    arr.push_back(curr->val);
                    left->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return arr;
    }
};