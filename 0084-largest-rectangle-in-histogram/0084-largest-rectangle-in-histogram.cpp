class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int> s;
        int nse = 0;
        int pse = 0;
        for(int i=0; i<heights.size(); i++){
            while(!s.empty()&&heights[s.top()]>heights[i]){
                int prev = heights[s.top()];
                s.pop();
                nse = i;
                pse = s.empty()?-1:s.top();
                max_area = max(max_area, prev*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            nse = heights.size();
            int element = heights[s.top()];
            s.pop();
            pse = s.empty()?-1:s.top();
            max_area = max(max_area, element*(nse-pse-1));
        }
        return max_area;
    }
};