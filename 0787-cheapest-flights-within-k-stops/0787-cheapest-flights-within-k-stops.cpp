class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialise the graph
        vector<vector<pair<int, int>>> graph(n);
        for(auto f:flights){
            // Node - {adj, price}
            graph[f[0]].push_back({f[1], f[2]});
        }
        // Create queue with {stop, {dist, node}}
        queue<pair<int,pair<int, int>>> q;
        q.push({0, {0, src}});
        // Initialise dist vector
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        // Perform BFS
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int stop=val.first;
            int d = val.second.first;
            int node = val.second.second;
            // Check the no of stops
            if(stop>k+1)continue;
            for(auto adj:graph[node]){
                int adjnode = adj.first;
                int price = adj.second;
                if(stop<k+1&&dist[adjnode]>d+price){
                    dist[adjnode] = d+price;
                    q.push({stop+1,{dist[adjnode], adjnode}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};