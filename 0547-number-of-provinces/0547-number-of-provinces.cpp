class Solution {
public:
    
    void dfs(vector<int> adj[], vector<int>& visited, int node){
        visited[node] = 1;
        for(int nei:adj[node]){
            if(visited[nei]==0){
                dfs(adj, visited, nei);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n  = isConnected.size();
        int c = isConnected[0].size();
        vector<int> visited(n,0);
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<c; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};