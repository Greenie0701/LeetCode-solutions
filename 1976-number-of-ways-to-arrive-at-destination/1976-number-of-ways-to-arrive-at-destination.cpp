class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);
        for (auto &r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;  // important

            for (auto &adj : graph[node]) {
                int adjnode = adj.first;
                int t = adj.second;
                long long newDist = time + t;

                if (newDist < dist[adjnode]) {
                    dist[adjnode] = newDist;
                    ways[adjnode] = ways[node];
                    pq.push({newDist, adjnode});
                } 
                else if (newDist == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
