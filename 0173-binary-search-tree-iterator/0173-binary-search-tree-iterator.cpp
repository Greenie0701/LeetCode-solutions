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
class BSTIterator {
private: stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        pushall(root, s);
    }
    
    int next() {
        auto node = s.top();
        s.pop();
        pushall(node->right, s);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

    void pushall(TreeNode* curr, stack<TreeNode*>& s){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */