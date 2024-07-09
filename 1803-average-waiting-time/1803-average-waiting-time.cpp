class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        queue<pair<int,int>> q;
        int n = customers.size();
        for(auto cus : customers) q.push({cus[0],cus[1]});
        int time = customers[0][0];
        double sum = 0;
        while(!q.empty()) {
            if(q.front().first<=time) {
                auto temp = q.front();
                q.pop();
                time += temp.second;
                sum += time - temp.first;
            }
            else {
                time = q.front().first;
            }
        }
        return (double)(sum)/n;
    }
};