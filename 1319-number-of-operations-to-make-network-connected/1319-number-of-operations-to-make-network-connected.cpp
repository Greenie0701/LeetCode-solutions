class disjointset{
    public:
    vector<int> parent;
    vector<int> rank;
    disjointset(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findparent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionbyrank(int u, int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv)return;
        // Check the rank
        if(rank[pu]==rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int nums = connections.size();
        if(n-1>nums)return -1;
        disjointset ds(n);
        for(auto c:connections){
            ds.unionbyrank(c[0], c[1]);
        }
        unordered_set<int> components;
        for(int i=0; i<n; i++){
            int parent = ds.findparent(i);
            if(components.find(parent)==components.end())components.insert(parent);
        }
        return components.size()-1;
    }
};