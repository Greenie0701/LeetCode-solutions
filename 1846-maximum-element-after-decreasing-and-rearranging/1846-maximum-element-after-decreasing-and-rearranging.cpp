class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Sort the array in increasing order
        sort(arr.begin(), arr.end());
        // Check if the first element is 1, if not set to 1
        if(arr[0]!=1)arr[0]=1;
        // Set maxi as 1;
        int maxi = arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }
};