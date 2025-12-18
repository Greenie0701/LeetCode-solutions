class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dist(row, vector<int>(col, -1));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<int> drow={1, -1, 0, 0};
        vector<int> dcol={0, 0, 1, -1};
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int r = val.first.first;
            int c = val.first.second;
            int d = val.second;
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col&&dist[nrow][ncol]==-1){
                    dist[nrow][ncol] = d+1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }
        return dist;
    }
};