class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Create a Priority Queue to perform Dijisktra
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        // Create distance vector to tract the effort taken so far
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // Initialise the src
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        // Perform BFS
        while(!pq.empty()){
            // Get the effect of curr
            int d = pq.top().first;
            // Get the co-ordinates
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            // Check you have reached the dest
            if(row==m-1&&col==n-1)return d;
            pq.pop();
            for(int i=0; i<4; i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                if(r>=0&&c>=0&&r<m&&c<n){
                    int neweffect = max(d, abs(heights[r][c]-heights[row][col]));
                    if(neweffect<dist[r][c]){
                        dist[r][c]=neweffect;
                        pq.push({neweffect,{r, c}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};