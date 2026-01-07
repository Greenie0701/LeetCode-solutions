class disjointset{
    public:
    // Create parent and rank vector
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    // Define the disjointset constructor
    disjointset(int n){
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        // Intially keep parent of node itself
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    // Find parent
    int findparent(int u){
        // BaseCase when parent of node itself
        if(parent[u]==u){
            return u;
        }
        //else backtrack 
        return parent[u]=findparent(parent[u]);
    }
    // Union by rank
    void unionbyrank(int u, int v){
        // Get the parents
        int pu = findparent(u);
        int pv = findparent(v);
        // Same parent which means same set
        if(pu==pv)return;
        // Same rank so join with any one of the parent and increase rank
        if(rank[pu]==rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        } 
        // Always attack smaller guy with larger rank guy
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
    int findsize(int u){
        int pu = findparent(u);
        return size[pu];
    }
    void unionbysize(int u, int v){
        // Get the parents
        int pu = findparent(u);
        int pv = findparent(v);
        // Same parent which means same set
        if(pu==pv)return;
        // Same size so join with any one of the parent and increase size
        if(size[pu]==size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        } 
        // Always attack smaller guy with larger size guy
        else if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        disjointset ds(m*n);
        vector<int> drow={1, -1, 0, 0};
        vector<int> dcol={0, 0, 1, -1};
        // Make the components of Island
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(!grid[row][col])continue;
                for(int i=0; i<4; i++){
                    int r=row+drow[i];
                    int c=col+dcol[i];
                    if(r>=0&&c>=0&&r<m&&c<n){
                        int node = row*n+col;
                        int adjnode = r*n+c;
                        if(grid[r][c]){
                            ds.unionbysize(node, adjnode);
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col])continue;
                unordered_set<int> components;
                for(int i=0; i<4; i++){
                    int r=row+drow[i];
                    int c=col+dcol[i];
                    if(r>=0&&c>=0&&r<m&&c<n){
                        int adjnode = r*n+c;
                        if(grid[r][c]){
                            int parent = ds.findparent(adjnode);
                            components.insert(parent);
                        }
                    }
                }
                int size=0;
                for(auto it:components){
                    size+=ds.findsize(it);
                }
                maxi=max(maxi, size+1);
            }
        }
        for(int i=0; i<m*n; i++){
            maxi = max(maxi, ds.findsize(ds.findparent(i)));
        }
        return maxi;
    }
};