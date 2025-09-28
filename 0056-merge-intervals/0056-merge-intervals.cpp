class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Create a 2D vector that contains non-overlapping intervals 
        vector<vector<int>> ans;
        // Sort the array 
        sort(intervals.begin(),intervals.end());
        // Iterate through the array
        for(int i=0;i<intervals.size();i++){
            // Check if the resultant array is empty or the previous interval is not part of current interval
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            // Else my previous interval overlaps with my current interval, so replace the previous end with 
            // max end of the current and previous intervals
            else{
                ans.back()[1]=max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};