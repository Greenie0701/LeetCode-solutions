class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int max_count=0;
        for(int n:nums){
            if(n){
                count++;
                max_count = max(count, max_count);
            }
            else{
                count=0;
            }
        }
        return max_count;
    }
};