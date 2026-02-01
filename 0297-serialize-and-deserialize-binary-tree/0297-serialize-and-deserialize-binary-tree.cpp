/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree="";
        if(!root)return tree;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node){
                tree.append(to_string(node->val)+",");
                q.push(node->left);
                q.push(node->right);
            }
            else{
                tree.append("#,");
            }
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        string str="";
        stringstream s(data);
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str!="#"){
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s, str, ',');
            if(str!="#"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));