class Solution {
public:
    int timer =1;
    void dfs(int parent, int node, vector<vector<int>>& graph, vector<int>& visited, vector<vector<int>>& bridges, vector<int>& tin, vector<int>& low){
        // Mark them as visited
        visited[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        // Iterate through the adj nodes
        for(int adjnode:graph[node]){
            if(adjnode==parent)continue;
            if(!visited[adjnode]){
                dfs(node, adjnode, graph, visited, bridges, tin, low);
                low[node] = min(low[node], low[adjnode]);
                if(low[adjnode]>tin[node]){
                    bridges.push_back({node, adjnode});
                }
            }
            else{
                low[node] = min(low[node], low[adjnode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<int> visited(n, 0);
        vector<int> tin(n,0);
        vector<int> low(n, 0);
        vector<vector<int>> graph(n);
        for(auto e:connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        // parent, node, visited, bridges, tin, low
        dfs(-1, 0, graph, visited, bridges, tin, low);
        return bridges;
    }
};