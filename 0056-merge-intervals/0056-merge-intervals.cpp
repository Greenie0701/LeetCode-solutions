class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(auto i:intervals){
            if(result.empty()||result.back()[1]<i[0]){
                result.push_back(i);
            }else{
                vector<int> prev = result.back();
                result.pop_back();
                prev[1] = prev[1]>=i[1]?prev[1]:i[1];
                result.push_back(prev);
            }
        }
        return result;
    }
};