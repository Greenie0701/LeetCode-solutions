class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = 1e9+7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        ways[0]=1;
        dist[0]=1;
        vector<vector<pair<int, int>>> graph(n);
        for(auto r:roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int node = val.second;
            long long d = val.first;
            for(auto adj:graph[node]){
                int adjnode = adj.first; 
                int wt = adj.second;
                if(dist[adjnode]>d+wt){
                    dist[adjnode]=d+wt;
                    ways[adjnode]=ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if(dist[adjnode]==d+wt){
                    ways[adjnode]= (ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};