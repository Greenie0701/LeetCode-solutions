class Solution {
public:
    void find(int k, int n, int index, vector<vector<int>>& result, vector<int>& subset, int sum){
        if(subset.size()==k && sum==n){
            result.push_back(subset);
            return;
        }
        if(subset.size()>k || sum>n){
            return;
        }
        for(int i=index; i<=9; i++){
            subset.push_back(i);
            sum+=i;
            find(k, n, i+1, result, subset, sum);
            subset.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> subset;
        find(k, n, 1, result, subset, 0);
        return result;
    }
};