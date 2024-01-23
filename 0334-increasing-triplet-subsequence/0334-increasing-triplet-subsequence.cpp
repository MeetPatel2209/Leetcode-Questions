class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto num : nums) {
            if(num<=a) {
                a=num;
            }
            else if(num<=b) {
                b=num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};