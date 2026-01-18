class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[nums[0]]=0;
        for(int i=1; i<nums.size(); i++){
            int remain = target-nums[i];
            if(m.find(remain)!=m.end()){
                return{i, m[remain]};
            }
            m[nums[i]]=i;
        }
        return {-1, -1};
    }
};