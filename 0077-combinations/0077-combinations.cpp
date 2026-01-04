class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& comb, int index, int n, int k){
        if(comb.size()==k){
            result.push_back(comb);
            return;
        }
        for(int i=index; i<=n; i++){
            comb.push_back(i);
            dfs(result, comb, i+1, n, k);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(result, comb, 1, n, k);
        return result;
    }
};