class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int workers = worker.size();
        int jobs = profit.size();
        vector<vector<int>> arr;
        for(int i=0; i<jobs; i++){
            arr.push_back({difficulty[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        int profits=0;
        for(int& w:worker){
            int i=0;
            int maxi = 0;
            while(i<jobs&&arr[i][0]<=w){
                maxi=max(maxi, arr[i][1]);
                i++;
            }
            profits+=maxi;
        }
        return profits;
    }
};