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


    pair<int, TreeNode*> dfs(TreeNode* root) {

        // Empty node has depth 0
        if (!root)
            return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Both sides have same depth
        if (left.first == right.first) {

            // Current node is answer
            return {left.first + 1, root};
        }

        // Left deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // Right deeper
        return {right.first + 1, right.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};