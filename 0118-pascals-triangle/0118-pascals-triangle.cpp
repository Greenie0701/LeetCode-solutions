class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Create an array that stores the pascal triangle
        vector<vector<int>> ans;
        // Always the the first row starts with zero
        ans.push_back({1});

        // Iterate through the array and from 1 to numRows, since 
        // the first row already added to result
        for (int i = 1; i < numRows; i++) {
            // Store prev row in a vector, to calculate the current row
            vector<int> prev = ans.back();
            vector<int> row;
            //Any row always start with 1 and ends with 1
            row.push_back(1); 
            // Iterate through previous array elements and find sum of j-1
            // and j and push to the row
            for (int j = 1; j < prev.size(); j++) {
                row.push_back(prev[j-1] + prev[j]);
            }
            //Any row always start with 1 and ends with 1
            row.push_back(1); 
            // Finally add the calculated row to the results array
            ans.push_back(row);
        }
        return ans;
    }
};
