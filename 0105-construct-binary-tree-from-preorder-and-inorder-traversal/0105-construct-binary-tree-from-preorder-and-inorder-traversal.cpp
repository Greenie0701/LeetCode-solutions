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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap;
        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);
    }
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& inmap){
        // Running out of elements, so return null
        if(is>ie||ps>pe)return NULL;
        // Create the root of the tree
        TreeNode* root = new TreeNode(preorder[ps]);
        int rootindex = inmap[preorder[ps]];
        int left = rootindex-is;
        root->left = build(preorder, ps+1, ps+left, inorder, is, rootindex-1, inmap);
        root->right = build(preorder, ps+left+1,pe, inorder, rootindex+1, ie, inmap);
        return root;
    }
};