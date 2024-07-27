class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        //sort(spells.begin(),spells.end());
        for(int i=0;i<spells.size();i++) {
            int ind;
            long long req = (success/spells[i]);
            if(success%spells[i] == 0) ind = lower_bound(potions.begin(),potions.end(),req) - potions.begin();
            else ind = upper_bound(potions.begin(),potions.end(),req) - potions.begin();
            spells[i] = n-ind;
        }
        return spells;
    }
};