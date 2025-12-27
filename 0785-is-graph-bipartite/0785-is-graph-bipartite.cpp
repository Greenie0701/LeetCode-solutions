class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& painted, int col, int node){
        painted[node] = col;
        for(int nei:graph[node]){
            if(painted[nei]==-1){
                if(!dfs(graph, painted, !col, nei))return false;
            }
            else if(painted[nei]==col)return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> painted(n, -1);
        int col = 0;
        for(int i=0; i<n; i++){
            if(painted[i]==-1){
                if(!dfs(graph, painted, col, i))return false;
            }
        }
        return true;
    }
};