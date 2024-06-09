class Solution {
public:
    int numberOfChild(int n, int k) {
        int pass = n-1;
        int cycle = k/pass;
        int rem = k - cycle*pass;
        if(cycle%2) {
            return n - rem - 1;
        }
        else {
            return rem;
        }
    }
};