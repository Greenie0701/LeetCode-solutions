class Solution {
public:
    void create(vector<vector<int>>& result, vector<int>& ds, vector<int>& nums, int index, int size){
        if(index==size){
            if(ds.size()==0){
                result.push_back({});
            }else{
                result.push_back(ds);
            }
            return;
        }
        ds.push_back(nums[index]);
        create(result, ds, nums, index+1, size);
        ds.pop_back();
        create(result, ds, nums, index+1, size);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        int size = nums.size();
        create(result, ds, nums, 0, size);
        return result;
    }
};