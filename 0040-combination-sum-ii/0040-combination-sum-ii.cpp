class Solution {
public:
    void findcombinesum(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& ans,int index, int total){
        if(target==total){
                result.push_back(ans);
                return;
        }
        if(index==candidates.size()||target<total){
            return;
        }
        if(candidates[index]<=target){
            ans.push_back(candidates[index]);
            findcombinesum(candidates, target, result, ans, index+1, total+candidates[index]);
            ans.pop_back();
        }
        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }
        findcombinesum(candidates, target, result, ans, index+1, total);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        findcombinesum(candidates, target, result, ans, 0, 0);
        return result;
    }
};