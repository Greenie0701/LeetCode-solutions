class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& chessboard, int n){
        // Search upper 
        for(int i=row; i>=0; --i){
            if(chessboard[i][col]=='Q')return false;
        }
        // Search top left
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(chessboard[i][j]=='Q')return false;
        }
        //
        // Search top right
        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(chessboard[i][j]=='Q')return false;
        }
        return true;
    }
    void search(int row, vector<vector<char>>& chessboard, vector<vector<string>>& result, int n){
        vector<string> ans;
        if(row==n){
            for(int i=0; i<n; i++){
                string temp(chessboard[i].begin(), chessboard[i].end());
                ans.push_back(temp);
            }
            result.push_back(ans);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(row, col, chessboard, n)){
                chessboard[row][col]='Q';
                search(row+1, chessboard, result, n);
                chessboard[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> chessboard(n, vector<char>(n, '.'));
        vector<vector<string>> result;
        search(0, chessboard, result, n);
        return result;
    }
};