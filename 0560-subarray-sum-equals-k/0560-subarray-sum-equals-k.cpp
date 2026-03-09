class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        int count = 0;
        int sum = 0;
        prefix_count[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(prefix_count.find(sum-k)!=prefix_count.end()){
                count+=prefix_count[sum-k];
            }
            prefix_count[sum]++;
        }
        return count;
    }
};

// 1 2 3 3 4   6
// 1 3 6 9 13
// 1 1 1 1 1

// 2