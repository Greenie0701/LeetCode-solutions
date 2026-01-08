class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto t:times){
            graph[t[0]].push_back({t[1], t[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int node = val.second;
            int time = val.first;
            if(dist[node]<time)continue;
            for(auto adj:graph[node]){
                int adjnode = adj.first;
                int wt = adj.second;
                if(dist[adjnode]>time+wt){
                    dist[adjnode]=time+wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1, dist.end());
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};