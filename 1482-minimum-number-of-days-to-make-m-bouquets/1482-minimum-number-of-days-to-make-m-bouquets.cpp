class Solution {
public:
    bool possible(vector<int>& arr, int mid, int m, int k){
        int num = 0;
        int boq = 0;
        for(int i=0; i<arr.size(); i++){
            if (arr[i] <= mid) {
                num++;
                if (num == k) {
                    boq++;
                    num = 0;
                }
            } else {
                num = 0; // break the consecutive chain
            }
        }
        return(boq>=m);
    }
    int minDays(vector<int>& arr, int m, int k) {
        if(long long(m)*k>arr.size()){
            return -1;
        }
        int ans =-1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(arr, mid, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};