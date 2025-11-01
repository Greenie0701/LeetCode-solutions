class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0; i<(1<<nums.size()); i++){
            vector<int> ans;
            for(int j=0; j<nums.size(); j++){
                if(i&(1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};