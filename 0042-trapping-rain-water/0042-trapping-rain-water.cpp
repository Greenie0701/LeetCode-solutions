class Solution {
public:
    int trap(vector<int>& height) {
        int r = height.size()-1;
        int l = 0;
        int maxl = height[l];
        int maxr = height[r];
        int max_area = 0;
        while(l<r){
            if(maxl<maxr){
                l++;
                maxl = max(maxl, height[l]);
                max_area+= maxl-height[l];
            }else{
                r--;
                maxr = max(maxr, height[r]);
                max_area+= maxr-height[r];
            }
        }
        return max_area;
    }
};