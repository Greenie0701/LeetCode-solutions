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
        // Get the number of stones
        int num = stones.size();
        // Get the maximum row and col
        int maxr=0;
        int maxc=0;
        for(auto s:stones){
            maxr = max(maxr, s[0]);
            maxc = max(maxc, s[1]);
        }
        // Initialise the disjoint set
        int offset = maxr + 1;
        disjointset ds(maxr + maxc + 2);
        // Create the unordered set to track the pos of x and y axis of stones
        unordered_set<int> pos;
        // Perform the union on stones
        for(auto s:stones){
            ds.unionbyrank(s[0], offset+s[1]);
            pos.insert(s[0]);
            pos.insert(offset+s[1]);
        }
        int components = 0;
        for(int node:pos){
            if(ds.findparent(node)==node){
                components++;
            }
        }
        return num-components;
    }
};