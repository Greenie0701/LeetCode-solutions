class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int count=1;
        for(char& c:s){
            if(st.find(c)!=st.end()){
                count++;
                st={};
            }
            st.insert(c);
        }
        return count;
    }
};
// a =3
// b =1
// c = 1
// count =2