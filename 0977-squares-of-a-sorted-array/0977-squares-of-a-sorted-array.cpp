class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        
        int n = arr.size();
        int index =  n;
        for(int i=0;i<n;i++) {
            if(arr[i]>0) {
                index = i;
                break;
            }
        }
        if(index == n) index = n-1;
        int l = index-1;
        int r = index;
        vector<int> res;
        while(l>=0 && r<n) {
            if(abs(arr[l])>abs(arr[r])) {
                res.push_back(arr[r]*arr[r]);
                r++;
            }
            else if(abs(arr[l])<abs(arr[r])) {
                res.push_back(arr[l]*arr[l]);
                l--;
            }
            else {
                res.push_back(arr[l]*arr[l]);
                res.push_back(arr[r]*arr[r]);
                r++;
                l--;
            }
        }
        while(l>=0) {
            res.push_back(arr[l]*arr[l]);
            l--;
        }
        while(r<n) {
            res.push_back(arr[r]*arr[r]);
            r++;
        }
        return res;
    }
};