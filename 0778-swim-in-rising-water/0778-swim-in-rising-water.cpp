class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Step 1 : Create a priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        // Step 2 : Create a distance vector
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        // Create 4 directional vector
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        // Step 3 : Perform the dijisktra
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int time = val.first;
            int row = val.second.first;
            int col = val.second.second;
            // Check you have reached the destination
            if(row==m-1&&col==n-1)return time;
            // Perform the search in four directions
            for(int i=0; i<4; i++){
                // New position
                int r = row+drow[i];
                int c = col+dcol[i];
                // Check if the new position are valid
                if(r>=0&&c>=0&&r<m&&c<n){
                    // Estimate the new time taken to reach new position
                    int t = max(time, grid[r][c]);
                    if(t<dist[r][c]){
                        dist[r][c]=t;
                        pq.push({t, {r, c}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};