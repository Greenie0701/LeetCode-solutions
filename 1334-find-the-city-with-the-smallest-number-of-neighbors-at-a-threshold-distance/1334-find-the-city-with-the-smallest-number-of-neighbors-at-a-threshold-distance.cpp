class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adj matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // Set diagnol dist as zero
        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }
        // Initialise the dist with given edges
        for(auto e:edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        // Perform the bellmanford algo
        for(int k=0; k<n; k++){ // Find path via intermediate node k
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){ // Iterate through the position(i, j)
                    // Check if there exists a valid path from i to k and then k to j
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        // Assign the shortest path by comparing via path k with existing path
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        // Now check the city with shortest path less than threshold
        int citycnt = INT_MAX; // Tracks the city with minimum city count within threshold
        int city = -1; // City with minimum city count
        for(int i=0; i<n; i++){
            int cnt=0; // Track the number of cities less than threshold
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold&&i!=j){
                    cnt++;
                }
            }
            // Found new city with smaller count or greater city with equal count
            if(cnt<=citycnt){
                citycnt = cnt;
                city = i;
            }
        }
        return city;
    }
};