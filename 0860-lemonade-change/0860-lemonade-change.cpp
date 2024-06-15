class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bill.begin(),bill.end());
        int five=0,ten=0,twenty=0;
        for(auto x : bills) {
            if(x == 5) {
                five++;
            }
            else if(x == 10) {
                if(five > 0) {
                    ten++;
                    five--;
                }
                else return false;
            }
            else {
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if(five > 2) {
                    five-=3;
                }
                else return false;
                twenty++;
            }
        }
        return true;
    }
};