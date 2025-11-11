class Solution {
public:
    int max_area(vector<int>& arr){
        stack<int> s;
        int maxi =0;
        for(int i=0;i<arr.size();i++){
            while(!s.empty()&&arr[s.top()]>arr[i]){
                int nse = i;
                int curr = arr[s.top()];
                s.pop();
                int pse = s.empty()?-1:s.top();
                maxi = max(maxi, curr*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int ns = arr.size();
            int cur = arr[s.top()];
            s.pop();
            int ps = s.empty()?-1:s.top();
            maxi = max(maxi, cur*(ns-ps-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefix_sum(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxi = 0;
        for(int j=0; j<matrix[0].size(); j++){
            int sum=0;
            for(int i=0; i<matrix.size(); i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0')sum=0;
                prefix_sum[i][j]=sum;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            maxi = max(maxi, max_area(prefix_sum[i]));
        }
        return maxi;
    }
};