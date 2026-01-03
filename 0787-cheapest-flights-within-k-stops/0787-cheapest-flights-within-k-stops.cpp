class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create a graph
        vector<vector<pair<int, int>>> graph(n);
        for(auto f:flights){
            graph[f[0]].push_back({f[1], f[2]});
        } 
        // dist vector - track price
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // Create a queue - {stops, {node, price}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        // Perform the bfs
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int stop = val.first;
            int city = val.second.first;
            int price = val.second.second;
            if(stop>k+1)continue;
            for(auto adj:graph[city]){
                int adjcity = adj.first;
                int wt = adj.second;
                if(stop+1<=k+1&&dist[adjcity]>price+wt){
                    dist[adjcity] = price+wt;
                    q.push({stop+1,{adjcity, price+wt}});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};