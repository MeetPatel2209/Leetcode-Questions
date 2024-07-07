class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int rem = 0;
        while(numBottles>=numExchange) {
            int empty = numBottles/numExchange;
            sum+=empty;
            rem = numBottles%numExchange;
            numBottles = empty + rem;
        }
        return sum ;
    }
};