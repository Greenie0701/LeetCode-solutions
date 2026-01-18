struct Node{
    Node* links[2];
    bool flag = false;
    void put(int bit, Node* node){
        links[bit]=node;
    }
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void setend(){
        flag=true;
    }
};

class trie{
    private: 
    Node* root;
    public:
    trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0;  i--){
            int bit = (num>>i)&1;
            if(!node->containskey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        node->setend();
    }
    int getmaxor(int num){
        Node* node = root;
        int maxi_xor = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containskey(1-bit)){
                maxi_xor = maxi_xor|(1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi_xor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        for(int i:nums){
            t.insert(i);
        }
        int maxi_or=0;
        for(int i:nums){
            maxi_or=max(maxi_or, t.getmaxor(i));
        }
        return maxi_or;
    }
};