class Solution {
public:
    bool check(vector<int> &nums, int dist, int k, int size){
        // Always place cow 
        int count = 1;
        int last = nums[0];
        for(int i = 1; i < size; i++){ 
            if(nums[i] - last >= dist){
                count++;
                last = nums[i];
            }
            if(count >= k){
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1;
        int high = nums[n-1] - nums[0];
        int ans = -1;
        // Perform binary search on low and high to find the mini diff btw any two is the max
        while(low <= high){
            int mid = low + (high - low) / 2;
          // Check atleast we can place k no of cows with mid as dist
            if(check(nums, mid, k, n)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

/*
nums = [1, 2, 4, 8, 9]
k = 2
*/
