class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        stack<char> st;
        int maxi = INT_MIN;
        for(auto c : s) {
            if(c == '(') {
                st.push(c);
                cnt++;
            }
            else if(c == ')') {
                st.pop();
                cnt--;
            }
            else continue;
            maxi = max(maxi,cnt);
        }
        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};