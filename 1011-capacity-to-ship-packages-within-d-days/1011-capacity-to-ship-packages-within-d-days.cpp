class Solution {
public:
    bool possible(vector<int>& weights, int cap, int days){
        int req=1;
        int sum=0;
        for(int n:weights){
            if(sum+n<=cap){
                sum+=n;
            }else{
                sum=n;
                req++;
            }
        }
        return req<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end());
        int ans=-1;
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