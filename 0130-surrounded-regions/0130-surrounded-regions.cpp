class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board,  vector<vector<int>>& visited,
    vector<int>& drow,  vector<int>& dcol){
        visited[r][c]=1;
        for(int i=0; i<4; i++){
            int row = r+drow[i];
            int col = c+dcol[i];
            if(row>=0&&row<board.size()&&col>=0&&col<board[0].size()&&!visited[row][col]&&board[row][col]=='O'){
                dfs(row, col, board, visited, drow, dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        // Directional array
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        // Search in the first and last row boundary for O
        for(int j=0; j<col; j++){
            if(board[0][j]=='O'&&!visited[0][j]){
                dfs(0, j, board, visited, drow, dcol);
            }
            if(board[row-1][j]=='O'&&!visited[row-1][j]){
                dfs(row-1, j, board, visited, drow, dcol);
            }
        }
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'&&!visited[i][0]){
                dfs(i, 0, board, visited, drow, dcol);
            }
            if(board[i][col-1]=='O'&&!visited[i][col-1]){
                dfs(i, col-1, board, visited, drow, dcol);
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'&&!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};