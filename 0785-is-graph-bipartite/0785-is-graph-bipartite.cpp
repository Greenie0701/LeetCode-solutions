class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int col, int node){
        visited[node] = col;

        for(int nei:graph[node]){
            if(visited[nei]==-1){
                if(!dfs(graph, visited, !col, nei))return false;
            }
            else if(visited[nei]==col)return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        int col = 0;
        for(int i=0; i<n; i++){
            if(visited[i]==-1){
                if(!dfs(graph, visited, col, i))return false;
            }
        }
        return true;
    }
};