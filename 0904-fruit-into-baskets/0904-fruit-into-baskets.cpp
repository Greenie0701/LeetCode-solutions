class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int l=0;
        int r=0;
        int end = fruits.size();
        int len = 0;
        while(r<end){
            m[fruits[r]]++;
            if(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)m.erase(fruits[l]);
                l++;
            }
            if(m.size()<=2){
                len = max(len, r-l+1);
            }
            r++;
        }
        return len;
    }
};