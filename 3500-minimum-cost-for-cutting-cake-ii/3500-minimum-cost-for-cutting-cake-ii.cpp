class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long cost = 0;
        long long hcut = 1;
        long long vcut = 1;
        priority_queue<pair<long long,bool>> pq;
        for(auto x : horizontalCut) {
            pq.push({x,true});
        }
        for(auto x : verticalCut) {
            pq.push({x,false});
        }
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(temp.second) {
                hcut++;
                cost += (temp.first*vcut);
            }
            else {
                vcut++;
                cost += (temp.first*hcut);
            }
        }
        return cost;
    }
};