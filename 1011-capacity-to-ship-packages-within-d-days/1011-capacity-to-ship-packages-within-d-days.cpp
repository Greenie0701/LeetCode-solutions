class Solution {
public:
    bool possible(vector<int>& weights, int k,  int days){
        int d =1;
        int current = 0;
        for(int i=0; i<weights.size(); i++){
            if (weights[i] > k) return false;
            if(current+weights[i]>k){
                d++;
                current=weights[i];
            }else{
                current+=weights[i];
            }
        }
        if(d<=days){
            return true;
        }else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // Find the range of capacity. It can hold either min element of capacity or max weight
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        // Find the minimum capacity where all weights can be shipped
        while(low<=high){
            int mid = low+(high - low)/2;
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