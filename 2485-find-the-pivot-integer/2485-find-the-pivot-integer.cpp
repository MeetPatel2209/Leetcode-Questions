class Solution {
public:
    int pivotInteger(int n) {
        int x=-1;
        int sum = ((n)*(n+1))/2;
        for(int i=n/2;i<=n;i++) {
            int temp = (i*(i+1))/2;
            int temp2 = sum - temp + i;
            if(temp == temp2) {
                return i;
            }
        }
        return -1;
    }
};