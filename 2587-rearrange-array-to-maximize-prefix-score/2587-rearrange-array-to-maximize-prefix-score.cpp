class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long prefix_sum=0;
        int count=0;
        for(int& n:nums){
            prefix_sum+=n;
            if(prefix_sum>0)count++;
        }
        return count;
    }
};