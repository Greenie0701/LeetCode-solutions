class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(); 
        int col = mat[0].size();
        vector<vector<int>> visited(row, vector<int>(col, -1));
        int dist = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==0){
                    visited[i][j]=0;
                    q.push({{i, j}, dist});
                }
            }
        }
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            int dist = front.second;
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col&&visited[nrow][ncol]==-1){
                    q.push({{nrow, ncol},dist+1});
                    visited[nrow][ncol] = dist+1;
                }
            }
        }
        return visited;
    }
};