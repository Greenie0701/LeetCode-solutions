class Solution {
public:

    void dfs(int node, vector<int>& visited, vector<int> adj[]){
        visited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                dfs(it, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};