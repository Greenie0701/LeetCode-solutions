class Solution {
public:

    vector<int> dijisktra(int n, vector<vector<pair<int, int>>>& graph, int src){
        // Create a distance vector
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        // Perform the dijistra 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int d = val.first;
            int node = val.second;
            // Iterate through the adj of nodes
            for(auto adj:graph[node]){
                int adjnode = adj.first;
                int wt = adj.second;
                if(dist[adjnode]>d+wt){
                    dist[adjnode]=d+wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int city = -1;
        int citycnt = INT_MAX;
        vector<vector<pair<int, int>>> graph(n);
        for(auto e:edges){
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }
        for(int i=0; i<n; i++){
            int count = 0;
            vector<int> dist = dijisktra(n, graph, i);
            for (int j = 0; j < n; j++) {
                if (j != i && dist[j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count<=citycnt){
                citycnt=count;
                city = i;
            }
        }
        return city;
    }
};