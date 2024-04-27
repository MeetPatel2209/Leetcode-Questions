class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;
    
    int countSteps(int i,int index,string ring) {
        int between = abs(index-i);
        int around = ring.size() - between;
        return min(between,around);
    } 
    
    int findSteps(int index,int ringIndex,string ring,string key,int minSteps) {
        if(dp[ringIndex][index]) {
            return dp[ringIndex][index];
        }
        if(index == key.size()) {
            return 0;
        }
        for(int i=0;i<ring.size();i++) {
            if(ring[i] == key[index]) {
                int totSteps = 1 + countSteps(i,ringIndex,ring) + findSteps(index+1,i,ring,key,INT_MAX);
                minSteps = min(minSteps,totSteps);
                dp[ringIndex][index] = minSteps;
            }
        }
        return minSteps;
    }
    
    
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        return findSteps(0,0,ring,key,INT_MAX);
    }
};