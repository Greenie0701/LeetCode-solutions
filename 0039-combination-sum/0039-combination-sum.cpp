class Solution {
public:
    void combination(vector<vector<int>>& result, vector<int>& ans, vector<int>& candidates, int target, int index){
        if(index==candidates.size()){
            if(target==0){
                result.push_back(ans);
            }
            return;
        }
        if(candidates[index]<=target){
            ans.push_back(candidates[index]);
            combination(result, ans, candidates, target-candidates[index], index);
            ans.pop_back();
        }
        combination(result, ans, candidates, target, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        combination(result, ans, candidates, target, 0);
        return result;
    }
};