class disjointset{
public:
    vector<int> parent, rank;
    disjointset(int n){
        parent.resize(n);
        rank.resize(n, 1);
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
        int ru = rank[pu];
        int rv = rank[pv];
        if(ru==rv){
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(ru>rv){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
        }
    }
};
/*
[[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]

 0 -> 1 -> 2

false, true
*/

class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // Sort by the distance
        sort(edgeList.begin(), edgeList.end(), comp);
        vector<vector<int>> query;
        int i=0;
        for(auto q:queries){
            query.push_back({q[0], q[1], q[2], i});
            i++;
        }
        // Sort by the query limit
        sort(query.begin(), query.end(), comp);
        // Create resultant  vector
        vector<bool> ans(query.size());
        disjointset ds(n);
        // Build the final answer
        int j = 0;
        for(auto q:query){
            while(j<edgeList.size()&&edgeList[j][2]<q[2]){
                ds.unionbyrank(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[q[3]]=ds.findparent(q[0])==ds.findparent(q[1]);
        }
        return ans;
    }
};