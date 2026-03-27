class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        int n = arr.size();
        if(n%3!=0)return {};
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        for(int i=0; i<n; i+=3){
            if(arr[i+2]-arr[i]<=k){
                result.push_back({arr[i], arr[i+1], arr[i+2]});
            }
            else{
                return {};
            }
        }
        return result;
    }
};