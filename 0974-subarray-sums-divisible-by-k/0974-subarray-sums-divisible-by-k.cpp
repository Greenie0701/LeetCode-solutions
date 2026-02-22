class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;

        int count = 0;
        int sum = 0;

        for(int n : nums) {
            sum += n;

            int mod = sum % k;

            if(mod < 0) 
                mod += k;

            if(prefix.find(mod) != prefix.end()) {
                count += prefix[mod];
            }

            prefix[mod]++;
        }

        return count;
    }
};