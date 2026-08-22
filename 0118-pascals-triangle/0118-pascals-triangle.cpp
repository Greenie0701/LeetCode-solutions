class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(!numRows)return result;
        // First row always zero
        result.push_back({1});
        // Start from second row & generate the remain n-1 rows
        for(int i=1; i<numRows; i++){
            // Define a empty vec to hold each row result
            vector<int> row;
            // First value of row is always 1
            row.push_back(1);
            // Start from sec value
            for(int j=1; j<result.back().size(); j++){
                row.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};