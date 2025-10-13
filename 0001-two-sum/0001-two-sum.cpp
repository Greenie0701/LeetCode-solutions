class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        int index = 0;
        for(int i:nums){
            arr.push_back({i, index});
            index++;
        }
        sort(arr.begin(), arr.end());
        int left = 0;
        int right =  nums.size()-1;
        while(left<right){
            int sum = arr[left].first+arr[right].first;
            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else{
                return {arr[left].second,arr[right].second};
            }
        }
        return {};
    }
};