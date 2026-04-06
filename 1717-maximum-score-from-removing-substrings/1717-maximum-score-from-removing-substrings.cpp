class Solution {
public:
    int removestr(string& s, char first, char second, int points){
        int result = 0;
        string temp;
        for(char& ch:s){
            if(!temp.empty()&&(temp.back()==first&&ch==second)){
                temp.pop_back();
                result+=points;
            }
            else{
                temp.push_back(ch);
            }
        }
        s=temp;
        return result;
    }


    int maximumGain(string s, int x, int y) {
        int result=0;
        // Lets greedily remove substr based upon the points
        if(x>y){
            result+=removestr(s, 'a', 'b', x);
            result+=removestr(s, 'b', 'a', y);
        }
        else{
            result+=removestr(s, 'b', 'a', y);
            result+=removestr(s, 'a', 'b', x);
        }
        return result;
    }
};