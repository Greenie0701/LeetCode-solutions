class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Initialise PQ for performing dijisktra
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        // Create a dist graph
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // Initialise the dist and pq with source;
        dist[0][0]=0;
        pq.push({0,{0, 0}});
        vector<int> drow = {1, -1, 0 ,0};
        vector<int> dcol = {0, 0, 1, -1};
        // Perform BFS
        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            // Check if this a dest
            if(row==m-1&&col==n-1)return d;
            pq.pop();
            for(int i=0; i<4; i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                if(r>=0&&c>=0&&r<m&&c<n){
                    int neweffort = max(d, abs(heights[row][col]-heights[r][c]));
                    if(neweffort<dist[r][c]){
                        dist[r][c]=neweffort;
                        pq.push({neweffort,{r, c}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};