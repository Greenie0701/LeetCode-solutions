class disjointset{
    public:
    vector<int> parent, size;
    disjointset(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    // FInd the parent 
    int findparent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findparent(parent[node]);
    }
    // Find the size of node
    int findsize(int node){
        int p = findparent(node);
        return size[p];
    }
    // Union by size
    void unionbysize(int u, int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv)return;
        int su = findsize(u);
        int sv = findsize(v);
        if(su==sv){
            parent[pv]=pu;
            size[pu]+=sv;
        }
        else if(su<sv){
            parent[pu]=pv;
            size[pv]+=su;
        }
        else{
            parent[pv]=pu;
            size[pu]+=sv;
        }
    }
};

class Solution {
public:
    bool isvalid(int row, int col, int m, int n){
        return(row<m&&col<n&&row>=0&&col>=0);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> drow={1, -1, 0, 0};
        vector<int> dcol={0, 0, 1, -1};
        disjointset ds(m*n);
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]){
                    for(int i=0; i<4; i++){
                        int r = drow[i]+row; 
                        int c = dcol[i]+col;
                        if(isvalid(r, c, m, n)){
                            int adjnode = r*n+c; 
                            int node = row*n+col;
                            if(grid[r][c]&&ds.findparent(node)!=ds.findparent(adjnode)){
                                ds.unionbysize(node, adjnode);
                            }
                        }
                    }
                }
            }
        }
        int max_area=0;
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                unordered_set<int> s;
                int sum = 0;
                if(!grid[row][col]){
                    for(int i=0; i<4; i++){
                        int r = drow[i]+row; 
                        int c = dcol[i]+col;
                        if(isvalid(r, c, m, n)){
                            int adjnode = r*n+c; 
                            if(grid[r][c]){
                                s.insert(ds.findparent(adjnode));
                            }
                        }
                    }
                }
                for(int it:s){
                    sum+=ds.findsize(it);
                }
                max_area=max(max_area, sum+1);
            }
        }
        for(int i=0; i<m*n; i++){
            max_area = max(max_area, ds.findsize(ds.findparent(i)));
        }
        return max_area;
    }
};