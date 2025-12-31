class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create a graph
        vector<vector<pair<int, int>>>  graph(n);
        for(auto f:flights){
            graph[f[0]].push_back({f[1], f[2]});
        }
        // Create distance vector
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        // Create queue storing pair of pair value {stops, {price, city}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        // Perform the normal BFS
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            // Get the values
            int stops = val.first; 
            int price = val.second.first;
            int city  = val.second.second;
            // check if the stops are with k+1 stops
            if(stops>k+1)continue;
            for(auto adj:graph[city]){
                int p = adj.second;
                int c = adj.first;
                if(stops+1<=k+1&&dist[c]>price+p){
                    dist[c]=p+price;
                    q.push({stops+1,{dist[c], c}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};