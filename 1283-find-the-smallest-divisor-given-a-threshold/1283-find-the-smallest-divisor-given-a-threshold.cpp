class Solution {
public:
    bool check(vector<int>& nums, int k, int threshold){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+= ceil(double(nums[i])/double(k));
        }
        if(sum<=threshold){
            return true;
        }else{
            return false;
        }
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // Find the divisor range - typically low as 1 to high as max element in the array
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        // Perform the binary search to find the smallest divisor
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(nums, mid, threshold)){
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