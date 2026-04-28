class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        // sort by end time
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the ballons by their end time
        sort(points.begin(), points.end(), comp);
        int arrows = 1;
        int max_end = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=max_end){
                continue;
            }
            else{
                arrows++;
                max_end = points[i][1];
            }
        }
        return arrows;
    }
};