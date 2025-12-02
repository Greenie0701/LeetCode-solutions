class Solution {
public:

    bool possible(vector<int>& weights, int limit, int days){
        int d = 1; // No of days req to fill the ship with limited weight
        int sum = 0; // Filling the ship with weights
        for(int i:weights){
            if(sum+i<=limit){
                sum+=i;
            }
            else if(d<days){
                sum = i;
                d++;
            }
            else{
                return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(weights, mid, days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};