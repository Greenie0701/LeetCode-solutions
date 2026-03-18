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
    int find(int u){
        if(parent[u]==u)return u;
        return parent[u]=find(parent[u]);
    }
    void union_by_rank(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)return;
        int ru = rank[pu];
        int rv = rank[pv];
        if(ru==rv){
            parent[pu]=pv;
            rank[pv]++;
        }
        else if(rv>ru){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
};

class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1)return true;
        disjointset ds(n);
        for(auto& e:edges){
            ds.union_by_rank(e[0], e[1]);
        }
        return ds.find(source)==ds.find(destination);
    }
};