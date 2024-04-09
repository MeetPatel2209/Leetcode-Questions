class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int i = 0;
        for(auto x : tickets) {
            q.push({x,i++});
        }
        int index = 0;
        int cnt = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            cnt++;
            int val = temp.first;
            val--;
            if(val == 0 && temp.second == k) return cnt;
            if(val>0) {
                q.push({val,temp.second});
            }
        }
        return -1;
    }
};