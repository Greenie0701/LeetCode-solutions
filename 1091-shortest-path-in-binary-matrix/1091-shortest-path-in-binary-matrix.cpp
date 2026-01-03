class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Edge case what if start pos {0, 0} or end pos {n, n} contains 1
        int size = grid.size();
        if(grid[0][0]||grid[size-1][size-1])return -1;
        // Create a visited array 
        vector<vector<int>> visited(size, vector<int>(size, 0));
        visited[0][0]=1;
        // Create queue for bfs
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        // perform search in 8 directions
        while(!q.empty()){
            auto val = q.front();
            int len = val.first;
            int row = val.second.first;
            int col = val.second.second;
            q.pop();
            if(row==size-1&&col==size-1)return len;
            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){
                    int r = row+i;
                    int c = col+j;
                    if(r>=0&&c>=0&&r<size&&c<size){
                        if(!grid[r][c]&&!visited[r][c]){
                            visited[r][c]=1;
                            q.push({len+1, {r, c}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};