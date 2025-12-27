class Solution {
public:

    void dfs(vector<vector<int>>& copy, vector<int>& drow, 
    vector<int>& dcol, int sr, int sc, int m, int n, int org, int color){
        copy[sr][sc] = color;
        for(int i=0; i<4; i++){
            int row = sr+drow[i];
            int col = sc+dcol[i];
            if(row>=0&&row<m&&col>=0&&col<n&&copy[row][col]==org){
                dfs(copy, drow, dcol, row, col, m, n, org, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        vector<vector<int>> copy = image;
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        int org = image[sr][sc]; 
        int m = image.size();
        int n = image[0].size();
        dfs( copy, drow, dcol, sr, sc, m, n, org, color);
        return copy;
    }
};