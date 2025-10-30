class Solution {
public:
    void generate(vector<int>& nums, vector<vector<int>>& powerset, vector<int>& subset, int index){
        if(index==nums.size()){
            powerset.push_back(subset);
            return;
        }
        generate(nums, powerset, subset, index+1);
        subset.push_back(nums[index]);
        generate(nums, powerset, subset, index+1);
        subset.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        generate(nums, powerset, subset, 0);
        return powerset;
    }
};