class Solution {
public:
    
    int doOp(int num1,int num2,char op) {
        if(op == '+') {
            return num1+num2;
        }
        if(op == '-') {
            return num2-num1;
        }
        if(op == '*') {
            return num1*num2;
        }
        if(op == '/') {
            return num2/num1;
        }
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto token : tokens) {
            if(st.empty() == true) {
                st.push(token);
            }
            else {
                if(token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                    int num1 = stoi(st.top());
                    st.pop();
                    int num2 = stoi(st.top());
                    st.pop();
                    int res = doOp(num1,num2,token[0]);
                    st.push(to_string(res));
                }
                else {
                    st.push(token);
                }
            }   
        }
        int ans = stoi(st.top());
        return ans;
    }
};