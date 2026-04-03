class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int count = 0;
        int i=0;
        int n = points.size();
        int curr_start = points[0][0];
        while(i<n){
            count++;
            while(i<n&&points[i][0]<=w+curr_start){
                i++;
            }
            if (i < n) {
                curr_start = points[i][0];
            }
        }
        return count;
    }
};