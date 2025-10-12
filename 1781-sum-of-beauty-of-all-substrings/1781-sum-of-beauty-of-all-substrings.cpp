class Solution {
public:
    int beautySum(string s) {
        // Basic Intution - Generate all the substring and its freq map
        // Iterate through freq map, find max and mini of freq, find the diff and add to the sum
        int result = 0;

        for(int i = 0; i<s.length(); i++){
            unordered_map<char, int> freq;
            for(int j = i; j<s.length(); j++){
                freq[s[j]]++;
                // find the maxi and mini
                int maxi = INT_MIN;
                int mini = INT_MAX;
                // Iterate through the freq map
                for(auto it:freq){
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                result+=maxi-mini;
            }
        }
        return result;
    }
};