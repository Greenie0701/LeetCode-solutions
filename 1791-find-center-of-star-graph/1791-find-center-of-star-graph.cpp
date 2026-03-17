class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int n = edges.size();
        // vector<int> indegree(n+2, 0);
        // for(auto e:edges){
        //     indegree[e[0]]++;
        //     indegree[e[1]]++;
        // }
        // int ans =-1;
        // for(int i=1; i<n+2; i++){
        //     if(indegree[i]==n){
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;
        vector<int> first_edge = edges[0];
        vector<int> second_edge = edges[1];
        return (first_edge[0]==second_edge[0]||second_edge[1]==first_edge[0])?first_edge[0]:first_edge[1];
    }
};