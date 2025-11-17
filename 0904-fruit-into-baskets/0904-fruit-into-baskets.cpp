class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l=0;
        int r=0;
        int len = 0;
        int size = fruits.size();
        while(r<size){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=2){
                len = max(len, r-l+1);
            }
            r++;
        }
        return len;
    }
};