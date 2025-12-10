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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildtree(index, preorder, INT_MAX);
    }

    TreeNode* buildtree(int& index, vector<int>& arr, int bound){
        if(index==arr.size()||arr[index]>bound){
            return NULL;
        }

        TreeNode* node = new TreeNode(arr[index]);
        index++;

        node->left = buildtree(index, arr, node->val);
        node->right = buildtree(index, arr, bound);

        return node;
    }
};