class Solution {
public:
    bool checkVowel(char c) {
        if(c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ||c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U' ) {
            return true;
        }
        else {
            return false;
        }
    }
    string reverseVowels(string s) {
        string vow;
        for(auto c : s) {
            if(checkVowel(c)) {
                vow.push_back(c);
            }
        }
        reverse(vow.begin(),vow.end());
        int ind=0;
        for(int i=0;i<s.size();i++) {
            if(checkVowel(s[i])) {
                s[i]=vow[ind++];
            }
        }
        return s;
    }
};