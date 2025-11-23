class Solution {
public:
    int maxi(vector<int>& arr){
        int max_area = 0;
        int nse = arr.size();
        int pse = -1;
        stack<int> s;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty()&&arr[s.top()]>arr[i]){
                nse = i;
                int prev = arr[s.top()];
                s.pop();
                pse = s.empty()?-1:s.top();
                max_area = max(max_area, prev*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            nse = arr.size();
            int pre = arr[s.top()];
            s.pop();
            pse = s.empty()?-1:s.top();
            max_area = max(max_area, pre*(nse-pse-1));
        }
        return max_area;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Initialise a prefix sum 
        vector<vector<int>> prefix_sum(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_area = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int j=0; j<col; j++){
            int sum = 0;
            for(int i=0; i<row; i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0')sum=0;
                prefix_sum[i][j]=sum;
            }
        }
        for(int i=0; i<row; i++){
            max_area = max(max_area, maxi(prefix_sum[i]));
        }
        return max_area;
    }
};