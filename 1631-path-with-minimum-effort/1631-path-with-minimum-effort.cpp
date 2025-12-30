class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Use Dijisktra to find the minimum path required to reach (rows-1, columns-1) from (0, 0)
        // Initialise Priority queue {dist, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // Create Distance vector
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        // Perform BFS
        int d = INT_MAX;
        // Initialise the directions 
        vector<int> drow ={1, -1, 0, 0};
        vector<int> dcol ={0, 0, 1, -1};
        while(!pq.empty()){
            // Get the distance
            int d = pq.top().first;
            // Get the co-ordinates
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            // If source is reached, end the iteration
            if(r==row-1&&c==col-1)return d;
            pq.pop();
            // Estimate the effort in all for directions
            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                // Check if the path is within bounds
                if(nrow>=0&&ncol>=0&&nrow<row&&ncol<col){
                    // Estimate the effort required
                    int neweffort = abs(heights[r][c]-heights[nrow][ncol]);
                    // Check if the effort is less than the previous, if yes update 
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow, ncol}});
                    }
                }
            }
        }
        return d;
    }
};