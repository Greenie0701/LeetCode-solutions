class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!indegree[i]){
                topo.push_back(i);
                q.push(i);
            } 
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjnode:adj[node]){
                indegree[adjnode]--;
                if(!indegree[adjnode]){
                    q.push(adjnode);
                    topo.push_back(adjnode);
                }
            }
        }
        return topo.size()==numCourses;
    }
};