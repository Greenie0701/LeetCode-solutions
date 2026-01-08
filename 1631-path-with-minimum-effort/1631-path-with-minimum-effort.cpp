class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        // Dist vector
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        // Create a directional vector
        vector<int> drow = {1, -1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        while(!pq.empty()){
            auto[effect, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;
            if(row==m-1&&col==n-1)return effect;
            for(int i=0; i<4; i++){
                int r = row+drow[i];
                int c = col+dcol[i];
                if(r>=0&&c>=0&&r<m&&c<n){
                    int neweffect = max(effect, abs(heights[r][c]-heights[row][col]));
                    if(dist[r][c]>neweffect){
                        dist[r][c]=neweffect;
                        pq.push({neweffect,{r,c}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};