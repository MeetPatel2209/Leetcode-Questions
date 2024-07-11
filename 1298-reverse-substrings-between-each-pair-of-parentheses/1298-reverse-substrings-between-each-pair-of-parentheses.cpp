class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ')') {
                string temp = "";
                while(st.top() != '(') {
                    temp = temp + st.top();
                    st.pop();
                }
                st.pop();
                for(int k=0;k<temp.size();k++) st.push(temp[k]);
            }
            else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while(st.empty() != true) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};