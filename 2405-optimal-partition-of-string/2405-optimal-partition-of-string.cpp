class Solution {
public:
    int partitionString(string s) {
        // Captures the char in the string
        int mask = 0;
        // Captures individual chars set bit
        int bit = 0;
        int count =1;
        // Go through every char in the string
        for(char& c:s){
            // Set the cth bit
            bit = 1<<(c-'a');
            // Now compare the bit with mask(captures the duplicate)
            if(mask&bit){
                mask = 0;
                count++;
            }
            // Add char to the mask
            mask|=bit;
        }
        return count;
    }
};