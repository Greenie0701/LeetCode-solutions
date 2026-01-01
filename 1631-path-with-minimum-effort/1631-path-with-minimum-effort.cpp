class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // Push the initial src
        pq.push({0,{0,0}});
        // Create a dist vector
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        // Create a 4 directions vector
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        // Perform dijisktra
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int effect = val.first;
            int row = val.second.first;
            int col = val.second.second;
            // Check we have reached the end
            if(row==m-1&&col==n-1)return effect;
            // Search in four directions
            for(int i=0; i<4; i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                // Check if they are valid pos
                if(r>=0&&c>=0&&r<m&&c<n){
                    int neweffect = max(effect, abs(heights[row][col]-heights[r][c]));
                    if(neweffect<dist[r][c]){
                        // Update the new effect for the pos
                        dist[r][c]=neweffect;
                        pq.push({neweffect,{r,c}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};