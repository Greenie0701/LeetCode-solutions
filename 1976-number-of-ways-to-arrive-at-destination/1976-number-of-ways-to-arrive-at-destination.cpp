class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        // Create a graph
        vector<vector<pair<int, int>>> graph(n);
        for(auto r:roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        set<pair<long long, int>> st;
        st.insert({0, 0});
        while(!st.empty()){
            auto val = *st.begin();
            st.erase(st.begin());
            long long d = val.first;
            int node = val.second;
            for(auto adj:graph[node]){
                int adjnode = adj.first;
                long long wt = adj.second;
                if(dist[adjnode]>d+wt){
                    dist[adjnode]= d+wt;
                    st.insert({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(dist[adjnode]==d+wt){
                    ways[adjnode]=((ways[adjnode]+ways[node])%mod);
                }
            }
        }
        return int(ways[n-1]);
    }
};