class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mincity = INT_MAX;
        int city = -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // initial configs
        for(auto e:edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        // Diagnol dist as 0
        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }
        // Perform the Floyd
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        // Count the cities less the the threshold and update the count
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i!=j&&dist[i][j]<=distanceThreshold)count++;
            }
            if(count<mincity){
                city = i;
                mincity = count;
            }
            else if(count==mincity){
                city = i;
            }
        }
        return city;
    }
};