class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss=1; // Initially empty 
        int i=0; // Pointer to the index of array
        int patches=0;
        int t = nums.size();
        while(miss<=n){
            // case 1: You can use use elements in nums
            if(i<t&&nums[i]<=miss){
                miss+=nums[i];
                i++;
            }
            // case 2: there is no elements in array or nums[i] is greater than miss
            else{
                miss+=miss;
                patches++;
            }
        }
        return patches;
    }
};