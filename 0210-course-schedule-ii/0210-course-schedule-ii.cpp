class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inorder(numCourses, 0);
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
            inorder[p[0]]++;
        }
        vector<int> result;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!inorder[i])q.push(i);
        }
        while(!q.empty()){
            int course = q.front();
            q.pop();
            result.push_back(course);
            for(int adjnode:graph[course]){
                inorder[adjnode]--;
                if(!inorder[adjnode]){
                    q.push(adjnode);
                }
            }
        }
        for(int i=0; i<numCourses; i++){
            if(inorder[i])return{};
        }
        return result;
    }
};