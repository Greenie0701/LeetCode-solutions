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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap;
        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]]=i;
        }
        return build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inmap);
    }
    TreeNode* build(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int>& inmap){
        if(ps>pe||is>ie){
            return NULL;
        }

        int rootindex = inmap[postorder[pe]];
        int left = rootindex-is;

        TreeNode* root = new TreeNode(postorder[pe]);

        root->left = build(postorder, pe-left, pe-1, inorder, is, rootindex-1, inmap);
        root->right = build(postorder, pe-left-1, 0, inorder, rootindex+1, ie, inmap);
    }
    
};