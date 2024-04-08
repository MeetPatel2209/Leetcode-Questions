class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto s : students) q.push(s);
        stack<int> st;
        int n = sandwiches.size();
        int cnt = 0;
        int sz = 0;
        for(int i=n-1;i>=0;i--) st.push(sandwiches[i]);
        while(!st.empty()) {
            if(st.top() == q.front()) {
                q.pop();
                st.pop();
                cnt = 0;
                continue;
            }
            else {
                cnt++;
                if(cnt == 1) {
                    sz = q.size();
                }
                if(cnt == sz) break;
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        if(st.empty()) return 0;
        else return q.size();
    }
};