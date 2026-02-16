class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int last_index = 0;
        int maxi = 1;
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(arr[i]%arr[prev]==0&&dp[i]<dp[prev]+1){
                    hash[i]=prev;
                    dp[i]=dp[prev]+1;
                }
            }
            if(maxi<dp[i]){
                last_index=i;
                maxi = dp[i];
            }
        }
        vector<int> temp;
        temp.push_back(arr[last_index]);
        while(hash[last_index]!=last_index){
            temp.push_back(arr[hash[last_index]]);
            last_index=hash[last_index];
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};