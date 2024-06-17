class Solution {
public:
    bool check(int num) {
        long long low = 0;
        long long high = num;
        while(low <= high) {
            long long mid = low + (high-low)/2;
            if(mid*mid == num) return true;
            else if(mid * mid < num) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    
    
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++) {
            int temp = c - (int)a*a;
            if(check(temp)) {
                return true;
            }
        }
        return false;
    }
};