class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Create an i index to track unique element
        int i =0;
        //iterate through the array to find unique elements
        for(int j=1; j<nums.size();j++){
            //Check whether the current element is unique
            if(nums[i]!=nums[j]){
                //If yes we found a unique key, so increment i
                i++;
                //Now store the jth element in ith index to track next unique element
                nums[i]=nums[j];
            }
        }
        //Zero indexing, so add 1 while returning
        return(i+1);
    }
};