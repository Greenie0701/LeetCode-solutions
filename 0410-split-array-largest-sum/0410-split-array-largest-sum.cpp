class Solution {
public:

    bool possible(vector<int>& nums, int k, int limit){
        int sum = 0;
        int num = 1;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]<=limit){
                sum+=nums[i];
            }else if(num<k){
                num++;
                sum=nums[i];
            }else{
                return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(nums, k, mid)){
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