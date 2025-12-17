class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited,
    vector<int>& drow, vector<int>& dcol){
        visited[row][col]=1;
        for(int i=0; i<4; i++){
            int r = row+drow[i];
            int c = col+dcol[i];
            if(r>=0&&r<board.size()&&c>=0&&c<board[0].size()&&!visited[r][c]&&board[r][c]=='O'){
                dfs(r, c, board, visited, drow, dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        for(int i=0; i<col; i++){
            if(!visited[0][i]&&board[0][i]=='O'){
                dfs(0, i, board, visited, drow, dcol);
            }
            if(!visited[row-1][i]&&board[row-1][i]=='O'){
                dfs(row-1, i, board, visited, drow, dcol);
            }
        } 
        for(int i=0; i<row; i++){
            if(!visited[i][0]&&board[i][0]=='O'){
                dfs(i, 0, board, visited, drow, dcol);
            }
            if(!visited[i][col-1]&&board[i][col-1]=='O'){
                dfs(i, col-1, board, visited, drow, dcol);
            }
        } 

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};