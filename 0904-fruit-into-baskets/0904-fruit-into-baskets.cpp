class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        unordered_map<int, int> m;
        int len = 0;
        int end = fruits.size();
        while(r<end){
            m[fruits[r]]++;
            while(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)m.erase(fruits[l]);
                l++;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};