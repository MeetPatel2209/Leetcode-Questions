class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++) {
            int num = i;
            int nextDig = i+1;
            while(num<=high && nextDig<=9) {
                num = num*10 + nextDig;
                if(low<=num && num<=high) ans.push_back(num);
                nextDig++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};