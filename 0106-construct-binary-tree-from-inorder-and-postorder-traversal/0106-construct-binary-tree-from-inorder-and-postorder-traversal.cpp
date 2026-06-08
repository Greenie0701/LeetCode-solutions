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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe, unordered_map<int, int>& inmap){
        if(is>ie||ps>pe)return NULL;

        int root_index = inmap[postorder[pe]];
        TreeNode* root = new TreeNode(inorder[root_index]);
        int left = root_index-is;
        root->left = dfs(inorder, postorder, is, root_index-1, ps, ps+left-1, inmap);
        root->right = dfs(inorder, postorder, root_index+1, ie, ps+left, pe-1, inmap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inmap[inorder[i]]=i;
        }
        return dfs(inorder, postorder, 0, n-1, 0, n-1, inmap);
    }
};