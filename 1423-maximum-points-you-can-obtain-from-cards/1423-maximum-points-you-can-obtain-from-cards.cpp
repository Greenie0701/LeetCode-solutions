class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        if(arr.size()==k){
            return accumulate(arr.begin(), arr.end(), 0);
        }
        int l = 0;
        int r = arr.size()-1;
        int sum=0;
        int maxi =0;
        for(int i=0; i<k; i++){
            sum+=arr[i];
        }
        maxi = sum;
        int index = k-1;
        for(int i=0; i<k; i++){
            sum-=arr[index];
            sum+=arr[r];
            maxi = max(maxi, sum);
            r--;
            index--;
        }
        return maxi;
    }
};