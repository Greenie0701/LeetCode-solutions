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
        if(pu == pv)return;
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
        int total = stones.size();
        // Get the maxi row and col
        int maxr = 0;
        int maxc = 0;
        for(auto s:stones){
            maxr = max(maxr, s[0]);
            maxc = max(maxc, s[1]);
        }
        disjointset ds(maxr+maxc+2);
        int offset = maxr+1;
        unordered_map<int> pos;
        for(auto s:stones){
            ds.unionbyrank(s[0], s[1]+offset);
            pos.insert(s[0]);
            pos.insert(s[1]+offset);
        }
        int comp = 0;
        for(int p:pos){
            if(ds.findparent(p)==p){
                comp++;
            }
        }
        return total-comp;
    }
};