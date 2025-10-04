class Solution {
public:
    int possible(vector<int>& bloomDay, int day, int m, int k){
        int pos = 0;
        int count = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                count++;
                if(count==k){
                    pos+=1;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        if(pos>=m){
            return 1;
        }else{
            return -1;
        }
    }
    int max_day(vector<int>& bloomDay, int size){
        int maxi = INT_MIN;
        for(int i=0; i<size; i++){
            maxi = max(bloomDay[i], maxi);
        }
        return maxi;
    }
    int min_day(vector<int>& bloomDay, int size){
        int mini = INT_MAX;
        for(int i=0; i<size; i++){
            mini = min(bloomDay[i], mini);
        }
        return mini;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Handle the edge case, where you have less no of flowers to make boques
        if(m*k>bloomDay.size())return -1;
        // Perform binary search
        int mini = INT_MAX;
        int low = min_day(bloomDay, bloomDay.size());
        int high = max_day(bloomDay, bloomDay.size());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, mid, m, k)==1){
                mini = min(mini, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return mini;
    }
};