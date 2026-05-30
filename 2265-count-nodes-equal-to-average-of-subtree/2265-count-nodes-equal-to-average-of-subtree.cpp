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
    int count = 0;
    pair<int, int> dfs(TreeNode* root){
        if(!root)return{0, 0};
        auto [leftsum, leftcnt] = dfs(root->left);
        auto [rightsum, rightcnt] = dfs(root->right);
        int sum = leftsum+rightsum+root->val;
        int cnt = leftcnt+rightcnt+1;;
        if(root->val==(sum/cnt))count++;
        return{sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};