class Solution {
public:
    int mod = 1e9+7;
    void dfs(int i, vector<int>& arr, int n, int k){
        if(i==k)return;

        for(int j=1; j<n; j++){
            arr[j]=(arr[j]+arr[j-1])%mod;
        }
        dfs(i+1, arr, n, k);
    }

    int valueAfterKSeconds(int n, int k) {
        vector<int> arr(n, 1);
        dfs(0, arr, n, k);
        return arr[n-1];
    }
};