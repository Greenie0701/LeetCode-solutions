class Solution {
public:
    bool search(int i, int j, vector<vector<char>>& board, string s, int index){
        if(index==s.length()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=s[index]){
            return false;
        }
        char c = board[i][j];
        board[i][j]='#';
        bool opt1 = search(i-1, j, board, s, index+1);
        bool opt2 = search(i, j-1, board, s, index+1);
        bool opt3 = search(i+1, j, board, s, index+1);
        bool opt4 = search(i, j+1, board, s, index+1);
        board[i][j] = c;
        return(opt1||opt2||opt3||opt4);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]==word[0]){
                    if(search(i, j, board, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};