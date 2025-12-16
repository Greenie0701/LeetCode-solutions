class Solution {
public:

    void dfs(vector<vector<int>>& image, vector<vector<int>>& result, int sr, int sc, int ini_color, int color, 
    vector<int>& drow, vector<int>& dcol){
        result[sr][sc]=color;
        for(int i=0; i<4; i++){
            int row = sr+drow[i];
            int col = sc+dcol[i];
            if(row>=0 && row<image.size() && col>=0 && col<image[0].size() &&
            result[row][col]!=color&&image[row][col]==ini_color){
                dfs(image, result, row, col, ini_color, color, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        vector<vector<int>> result = image;
        int Ini_color = image[sr][sc];
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0 ,0 , 1, -1};
        dfs(image, result, sr, sc, Ini_color, color, drow, dcol);
        return result;
    } 
};