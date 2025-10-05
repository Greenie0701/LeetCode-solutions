class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int bqcount = 0;
        for(int i=0; i<bloomDay.size(); i++){
            // Check if the flower is bloomed within day
            if(bloomDay[i]<=day){
                // Increase the count, since the flower is bloomed
                count++;
                // If count is reached to k flowers, then yes one boq made
                if(count==k){
                    bqcount++;
                    count =0;
                }
            }
            // Else restart the count
            else{
                count = 0;
            }
        }
        if(bqcount>=m){
            return true;
        }else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Handle the edge case where there is no enough flowers to make bouquet
        long long val = (long long)m*(long long)k;
        if(val>bloomDay.size()){
            return -1;
        }
        // Low = Minimum day taken to bloom one flower
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        // High = Maximum day taken to bloom all flowers
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        // Iterate through the range to find the min days to make k no of bouquets
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(bloomDay, mid, m, k)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};