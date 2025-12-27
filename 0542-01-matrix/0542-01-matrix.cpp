class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    matrix[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int row = r+drow[i];
                int col = c+dcol[i];
                if(row>=0&&row<m&&col>=0&&col<n&&matrix[row][col]==-1){
                    q.push({{row, col}, d+1});
                    matrix[row][col] = d+1;
                }
            }
        }
        return matrix;
    }
};