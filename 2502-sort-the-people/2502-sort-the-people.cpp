class Solution {
public:
    bool static comp(pair<int,string> &A,pair<int,string> &B) {
        return A.first > B.first;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int,string>> arr(n);
        for(int i=0;i<n;i++) {
            arr[i] = {heights[i],names[i]};
        }
        sort(arr.begin(),arr.end(),comp);
        for(int i =0; i<n;i++) {
            names[i] = arr[i].second;
        }
        return names;
    }
};