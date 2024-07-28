class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0;
        int rem1 = 0;
        int sum2 =0 ;
        int rem2 = 0;
        for(auto x : nums) {
            if(1<=x && x <=9) sum1+=x;
            else rem1+=x;
            if(10<=x && x<=99) sum2+=x;
            else rem2 += x;
        }
        if(sum1>rem1 || sum2 > rem2) return true;
        else return false;
    }
};