class Solution {
public:
    int passThePillow(int n, int time) {
        int cnt = time/(n-1);
        int rem = time%(n-1);
        if(cnt & 1) return n-rem;
        else return rem+1;
    }
};