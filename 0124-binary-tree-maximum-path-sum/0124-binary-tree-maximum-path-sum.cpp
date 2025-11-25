class Solution {
public:
    int maxpathsum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        // Compute left and right subtree sums, but ignore negatives
        int leftsum = max(0, maxpathsum(root->left, maxi));
        int rightsum = max(0, maxpathsum(root->right, maxi));

        // Update global maximum
        maxi = max(maxi, root->val + leftsum + rightsum);

        // Return the best one-side path sum (for parent use)
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpathsum(root, maxi);
        return maxi;
    }
};
