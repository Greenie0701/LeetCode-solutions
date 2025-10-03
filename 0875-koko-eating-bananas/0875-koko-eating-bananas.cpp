class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = INT_MAX;
        int low = 1;
        int high = findMax(piles);
        while(low<=high){
            // find the mid of k 
            int mid = low + (high - low)/2;
            long long k = 0;
            // Calculate the total hours taken to complete the total piles with mid
            for(int i = 0; i<=piles.size()-1; i++){
                k += ceil(double(piles[i])/double(mid));
            }
            // Check if the calculated k hours is less than or eq given hours
            if(k<=h){
                min_speed = min(min_speed, mid);
                high = mid-1;
            }
            // Calculated K is not enough so search from right
            else{
                low=mid+1;
            }
        }
        return min_speed;
    }
};