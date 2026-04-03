class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return (checkValid(n, rectangles, true)||checkValid(n, rectangles, false));
    }

    bool checkValid(int& n, vector<vector<int>>& rectangles, bool horizontal){
        vector<vector<int>> intervals;
        for(auto& r:rectangles){
            if(horizontal){
                intervals.push_back({r[0], r[2]}); // startx, endx
            }
            else{
                intervals.push_back({r[1], r[3]}); // starty, endy
            }
        }
        int gap = 0;
        sort(intervals.begin(), intervals.end());
        int current_end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=current_end){
                gap++;
            }
            current_end = max(current_end, intervals[i][1]);
        }
        return gap>=2;
    }
};