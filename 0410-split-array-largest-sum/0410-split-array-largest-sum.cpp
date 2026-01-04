class Solution {
public:

    // Helper function to count the sub arrays with sum max sum asmid
    int count(vector<int>& arr, int maxi){
        int count=1;
        int sum =0;
        for(int n:arr){
            // If the sum plus next number is within maxi 
            if(sum+n<=maxi){
                sum+=n;
            }
            // Else reinitialise the sum with n and increase the count
            else{
                count++;
                sum = n;
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        // The lowest split I can make should the maxi element of the arry
        /*
        7, 2, 5, 10, 8
        2
        10 - 32
        21
        10 - 20
        16 - 20
        18
        16 - 19
        17

        */

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        // Apply binary search to find the optimal val
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(count(nums, mid)<=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};