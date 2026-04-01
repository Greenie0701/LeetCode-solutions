class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxi_score=0;
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size()-1;
        while(left<=right){
            if(power>=tokens[left]){
                power-=tokens[left];
                left++;
                score++;
            }
            else if(score){
                score--;
                power+=tokens[right];
                right--;
            }
            else{
                break;
            }
            if(score>maxi_score)maxi_score=score;
        }
        return maxi_score;
    }
};