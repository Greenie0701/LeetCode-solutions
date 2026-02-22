class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix;
        prefix[0] = -1;  // VERY IMPORTANT

        int maxLen = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                sum += 1;
            else
                sum -= 1;

            if(prefix.find(sum) != prefix.end()) {
                maxLen = max(maxLen, i - prefix[sum]);
            } 
            else {
                // store only first occurrence
                prefix[sum] = i;
            }
        }

        return maxLen;
    }
};