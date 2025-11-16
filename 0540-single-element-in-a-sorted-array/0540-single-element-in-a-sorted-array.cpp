class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int single=0;
        for(int n:nums){
            single = single^n;
        }
        return single;
    }
};