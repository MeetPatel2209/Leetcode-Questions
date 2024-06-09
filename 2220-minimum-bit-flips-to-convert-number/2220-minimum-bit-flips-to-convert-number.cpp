class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int cnt = 0;
        //int i = 0;
        while(temp != 0) {
            if(temp & 1) cnt++;
            //i++;
            temp = temp >> 1;
        }
        return cnt;
    }
};