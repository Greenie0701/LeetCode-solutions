class disjointset{
    public:
    vector<int> parent, rank;
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
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int> pos;
        int maxr=INT_MIN;
        int maxc=INT_MIN;
        for(auto p:stones){
            maxr=max(maxr,p[0]);
            maxc=max(maxc, p[1]);
        }
        int offset = maxr+1;
        disjointset ds(maxc+maxr+2);
        int parent_stone=0;
        for(auto s:stones){
            ds.unionbyrank(s[0], s[1]+offset);
            pos.insert(s[0]);
            pos.insert(s[1]+offset);
        }
        for(int it:pos){
            if(ds.findparent(it)==it)parent_stone++;
        }
        return stones.size()-parent_stone;
    }
};