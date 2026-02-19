class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int l =0;
        int r = height.size()-1;
        while(l<r){
            int h = min(height[l], height[r]);
            maxi = max(maxi, h*(r-l));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};