class Solution {
public:
    bool isvalid(int r, int c, int row, int col){
        return(r>=0&&c>=0&&r<row&&c<col);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]||grid[m-1][n-1])return -1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0]=1;
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int step = val.first;
            int row  = val.second.first;
            int col  = val.second.second;
            if(row==m-1&&col==n-1)return step;
            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){
                    int r = row+i;
                    int c = col+j;
                    if(isvalid(r, c, m, n)){
                        if(!grid[r][c]){
                            q.push({step+1, {r, c}});
                            grid[r][c]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};