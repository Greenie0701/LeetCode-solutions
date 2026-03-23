class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int bit = 0;
        int count =1;
        for(char& c:s){
            bit = 1<<(c-'a');
            if(mask&bit){
                count++;
                mask = 0;
            }
            mask|=bit;
        }
        return count;
    }
};