class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (auto &str : tokens) {
            
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();

                if (str == "+") s.push(num2 + num1);
                else if (str == "-") s.push(num2 - num1);
                else if (str == "*") s.push(num2 * num1);
                else s.push(num2 / num1);
            }
            else {
                s.push(stoi(str));   // convert string to integer
            }
        }

        return s.top();
    }
};