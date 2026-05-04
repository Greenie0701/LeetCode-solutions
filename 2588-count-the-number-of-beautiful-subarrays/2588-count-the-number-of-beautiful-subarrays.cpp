class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        unordered_map<int, long long> m;
        m[0] = 1;  // Important: handles subarrays starting from index 0
        
        int prefix = 0;
        
        for(int i = 0; i < n; i++){
            prefix ^= nums[i];
            
            ans += m[prefix];  // count how many times we've seen this prefix
            
            m[prefix]++;       // update frequency
        }
        
        return ans;
    }
};