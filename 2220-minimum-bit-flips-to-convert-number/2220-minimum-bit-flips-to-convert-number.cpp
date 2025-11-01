class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        string s="";
        int count=0;
        while(ans>=1){
            s=to_string(ans&1)+s;
            ans=ans>>1;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
};