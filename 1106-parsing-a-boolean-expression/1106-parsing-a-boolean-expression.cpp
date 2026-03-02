class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(char c:expression){
            if(c==',')continue;
            else if(c=='|'||c=='!'||c=='&'||c=='('||c=='t'||c=='f'){
                s.push(c);
            }
            else{
                int t = 0;
                int f =0;
                while(!s.empty()&&s.top()!='('){
                    if(s.top()=='f'){
                        f++;
                    }
                    else{
                        t++;
                    }
                    s.pop();
                }
                s.pop();
                if(!s.empty()){
                    char exp = s.top();
                    s.pop();
                    if(exp=='|'){
                        s.push(t>0?'t':'f');
                    }
                    else if(exp=='&'){
                        s.push(f==0?'t':'f');
                    }
                    else{
                        s.push(f==1?'t':'f');
                    }
                }
            }
        }
        return s.top()=='t';
    }
};