class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            result.push_back(course);
            for(int dep:graph[course]){
                indegree[dep]--;
                if(!indegree[dep])q.push(dep);
            }
        }
        if(result.size()!=numCourses)return {};
        return result;
    }
};