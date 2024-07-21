class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto c : s) {
            if(isVowel(c)) cnt++;
        }
        if(cnt == 0) return false;
        if(cnt%2 != 0) return true;
        else {
            return true;
        }
    }
};