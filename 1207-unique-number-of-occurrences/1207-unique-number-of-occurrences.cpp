class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_set<int> s;
        int cnt = 1;
        for(int i=1;i<n;i++) {
            if(arr[i] == arr[i-1]) {
                cnt++;
            }
            else {
                if(s.find(cnt) != s.end()) {
                    return false;
                }
                s.insert(cnt);
                cnt = 1;
            }
        }
        if(s.find(cnt) != s.end()) {
            return false;
        }
        return true;
    }
};