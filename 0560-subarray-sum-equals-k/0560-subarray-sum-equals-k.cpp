class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int count = 0;
        int sum=0;
        prefix[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(prefix.find(sum-k)!=prefix.end()){
                count+=prefix[sum-k];
            }
            prefix[sum]++;
        }
        return count;
    }
};