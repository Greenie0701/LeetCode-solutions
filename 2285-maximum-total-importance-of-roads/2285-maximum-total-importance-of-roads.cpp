class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long result=0;
        vector<int> degree(n, 0);
        for(vector<int>& r:roads){
            degree[r[0]]++;
            degree[r[1]]++;
        }
        sort(degree.begin(), degree.end());
        for(int i=1; i<=n; i++){
            result+=(degree[i-1]*i);
        }
        return result;
    }
};