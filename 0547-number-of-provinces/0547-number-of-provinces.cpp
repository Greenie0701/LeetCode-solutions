class Solution {
public:

    void dfs(int src, vector<int>& visited, vector<int> adj[]){
        visited[src] = 1;
        for(int node:adj[src]){
            if(!visited[node]){
                dfs(node, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};