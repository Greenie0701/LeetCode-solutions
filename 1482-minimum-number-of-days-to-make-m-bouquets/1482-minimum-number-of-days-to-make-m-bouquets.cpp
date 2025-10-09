class Solution {
public:
    bool possible(vector<int>& bloomDay, int n,  int m, int k){
        int count =0;
        int b = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=n){
                count++;
                if(count==k){
                    b++;
                    count =0;
                }
            }else{
                count = 0;
            }
        }
        if(b>=m){
            return true;
        }else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1ll*(k)*1ll;
        int ans = -1;
        if( val > bloomDay.size()){
            return ans;
        }
        // flowers bloom in first day to last day - Range
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        // Perform the binary search 
        while(low<=high){
            int mid = low + (high-low)/2;
            // Check with this mid can you make boque
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};