class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialise the element by minimum integer value
        int element=INT_MIN;
        // Initialise the count as zero, as no one dominates
        // Moore’s Voting Algorithm
        int count=0;
        for(int i=0;i<nums.size();i++){
            // If count is zero, which means the prev major element 
            // got nullified, so assume my current candidate as majorelement
            if(count ==0){
                count=1;
                element = nums[i];
            }
            // If my current element is actual candidate, increment count
            else if(nums[i]==element){
                count++;
            }
            // Else decrement my count
            else{
                count--;
            }
        }
        return element;
    }
};