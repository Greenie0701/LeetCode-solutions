class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());  // sort by value

        int left = 0, right = arr.size()-1;
        while(left < right) {
            int sum = arr[left].first + arr[right].first;
            if(sum < target) {
                left++;
            } else if(sum > target) {
                right--;
            } else {
                return {arr[left].second, arr[right].second};
            }
        }
        return {}; // should not reach here
    }
};
