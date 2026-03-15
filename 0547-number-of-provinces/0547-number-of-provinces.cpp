class Solution {
public:

    void dfs(vector<int>& visited, vector<int> adj[], int node){
        visited[node] = 1;
        for(int nei:adj[node]){
            if(!visited[nei]){
                dfs(visited, adj, nei);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int size = isConnected.size();
        vector<int> adj[size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(size, 0);
        for(int i=0; i<size; i++){
            if(!visited[i]){
                count++;
                dfs(visited, adj, i);
            }
        }
        return count;
    }
};