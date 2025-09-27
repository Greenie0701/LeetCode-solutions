class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Create a resultant array to return 4sum
        vector<vector<int>> result;
        // Sort the array, requires for breaking down 4sum to 2 sum
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            // Find the first index of quadruplet
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
                // Find the second index of quadruplet
                if(j>i+1 && nums[j]==nums[j-1])continue;  
                // Now perform the 2 sum approach for remaining two indexes
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    // Find the sum of the array
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    // Check the sum and target are equal
                    if(sum==target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(temp);
                        // Move the k & l index to next value
                        k++;
                        l--;
                        // Skip duplicate values
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    // If sum is lesser than my target
                    else if(sum<target){
                        k++;
                    }
                    // If sum is greater than my target
                    else{
                        l--;
                    }
                }             
            }
        }
        return result;
    }
};