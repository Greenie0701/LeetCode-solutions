class Solution {
public:
    vector<int> findnse(vector<int>& heights, vector<int>& nse){
        stack<int> s;
        int size=heights.size();
        for(int i=size-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                nse[i] = s.top();
            }
            s.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& heights, vector<int>& pse){
        stack<int> s;
        int size=heights.size();
        for(int i=0; i<size; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                pse[i] = s.top();
            }
            s.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> nse(size, size);
        vector<int> pse(size, -1);
        nse = findnse(heights, nse);
        pse = findpse(heights, pse);
        int max_area = 0;
        for(int i=0; i<heights.size(); i++){
            max_area = max(max_area, heights[i]*(nse[i]-pse[i]-1));
        }
        return max_area;
    }
};