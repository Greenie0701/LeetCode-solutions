class Solution {
public:
    
    void dfs(vector<vector<int>>& copy, vector<vector<int>>& image, vector<int> drow, vector<int> dcol,
    int sr, int sc, int ini_color, int color){
        copy[sr][sc] = color;
        for(int i=0; i<4; i++){
            int r = sr+drow[i];
            int c = sc+dcol[i];
            if(r>=0&&r<image.size()&&c>=0&&c<image[0].size()&&image[r][c]==ini_color&&copy[r][c]!=color){
                dfs(copy, image, drow, dcol, r, c, ini_color, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        vector<vector<int>> copy = image;
        int ini_color = image[sr][sc];
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        dfs(copy, image, drow, dcol, sr, sc, ini_color, color);
        return copy;
    }
};