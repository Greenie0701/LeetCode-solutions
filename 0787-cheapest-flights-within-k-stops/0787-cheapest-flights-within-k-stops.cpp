class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Create the graph {dest, price}
        vector<vector<pair<int, int>>> graph(n);
        for(auto f:flights){
            graph[f[0]].push_back({f[1], f[2]});
        }
        // Create a queue ds with the following pairs - {stops, {price, node}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        // Create a dist vector
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // Perform BFS
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int stops = val.first;
            int city = val.second.first;
            int price = val.second.second;
            // Check if the stops are less k+1
            if(stops>k+1)continue;
            for(auto next:graph[city]){
                int nextcity = next.first;
                int p = next.second;
                if(stops+1<=k+1&&dist[nextcity]>p+price){
                    dist[nextcity] = p+price;
                    q.push({stops+1, {nextcity,dist[nextcity]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};