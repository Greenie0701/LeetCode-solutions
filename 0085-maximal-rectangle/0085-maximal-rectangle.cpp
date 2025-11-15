class Solution {
public:
    int find_area(vector<int>& arr){
        int max_area = 0;
        stack<int> s;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty()&&arr[s.top()]>arr[i]){
                int nse = i;
                int prev =  arr[s.top()];
                s.pop();
                int pse = s.empty()?-1:s.top();
                max_area = max(max_area, prev*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int ns = arr.size();
            int pre = arr[s.top()];
            s.pop();
            int ps = s.empty()?-1:s.top();
            max_area = max(max_area, pre*(ns-ps-1));
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefix_sum(matrix.size(), vector<int>(matrix[0].size(), 0));
        int row = matrix.size();
        int col = matrix[0].size();
        int max_area =0;
        for(int j=0; j<col; j++){
            int sum = 0;
            for(int i=0; i<row; i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0'){
                    prefix_sum[i][j]=0;
                    sum = 0;
                }else{
                    prefix_sum[i][j] = sum;
                }
            }
        }
        for(int i=0; i<row; i++){
            max_area = max(max_area, find_area(prefix_sum[i]));
        }
        return max_area;
    }
};