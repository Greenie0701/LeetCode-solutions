class Solution {
public:

    int area(vector<int>& arr){
        int maxi = 0;
        vector<int> s;
        int nse = 0;
        int pse = 0;
        int ele = 0;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty()&&arr[s.back()]>arr[i]){
                nse = i;
                ele = arr[s.back()];
                s.pop_back();
                pse = s.empty()?-1:s.back();
                maxi = max(maxi, ele*(nse-pse-1));
            }
            s.push_back(i);
        }
        while(!s.empty()){
            nse = arr.size();
            ele = arr[s.back()];
            s.pop_back();
            pse = s.empty()?-1:s.back();
            maxi = max(maxi, ele*(nse-pse-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefix_sum(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_area = 0;
        for(int j=0; j<matrix[0].size(); j++){
            int sum = 0;
            for(int i=0; i<matrix.size(); i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0')sum=0;
                prefix_sum[i][j]=sum;
            }
        }
        for(int i=0; i<prefix_sum.size(); i++){
            max_area = max(max_area, area(prefix_sum[i]));
        }
        return max_area;
    }
};