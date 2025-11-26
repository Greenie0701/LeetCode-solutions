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
    int findmaxsum(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int leftsum = max(findmaxsum(root->left, maxi), 0);
        int rightsum = max(findmaxsum(root->right, maxi), 0);

        maxi = max(maxi, root->val+leftsum+rightsum);

        return root->val+max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxsum(root, maxi);
        return maxi;
    }
};