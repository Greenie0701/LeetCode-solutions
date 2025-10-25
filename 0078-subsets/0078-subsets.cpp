class Solution {
public:
    void findsubset(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans,int index,int size){
        if(index>size){
            if(curr.size()==0){
                ans.push_back({});
                return;
            }
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        findsubset(nums, curr, ans, index+1, size);
        curr.pop_back();
        findsubset(nums, curr, ans, index+1, size);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        findsubset(nums,curr, ans, 0, nums.size()-1);
        return ans;
    }
};