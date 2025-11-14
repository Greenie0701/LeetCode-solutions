class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxL = height[left];
        int maxR = height[right];
        int potential_water = 0;
        while(left<right){
            if(maxL<maxR){
                left++;
                maxL = max(maxL, height[left]);
                potential_water+=maxL-height[left];
            }else{
                right--;
                maxR = max(maxR, height[right]);
                potential_water+=maxR-height[right];
            }
        }
        return potential_water;
    }
};