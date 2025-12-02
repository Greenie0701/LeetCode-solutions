class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long minindex = q.front().second;
            unsigned long long first = 0, last = 0;
            
            for (int i = 0; i < size; i++) {
                unsigned long long curr_index = q.front().second - minindex;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = curr_index;
                if (i == size - 1) last = curr_index;
                
                if (node->left) q.push({node->left, 2 * curr_index + 1});
                if (node->right) q.push({node->right, 2 * curr_index + 2});
            }
            
            width = max(width, last - first + 1);
        }
        
        return (int)width;
    }
};
