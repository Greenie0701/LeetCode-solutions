class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int& m, int& n){
        visited[i][j] = true;
        for(int x=0; x<4; x++){
            int r = i+dx[x];
            int c = j+dy[x];
            if(r>=0&&c>=0&&r<m&&c<n&&grid[r][c]-'0'&&!visited[r][c]){
                dfs(grid, visited, r, c, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int island = 0;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]-'0'&!visited[r][c]){
                    island++;
                    dfs(grid, visited, r, c, m, n);
                }
            }
        }
        return island;
    }
};