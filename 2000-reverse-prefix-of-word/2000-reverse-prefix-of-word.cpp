class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int i;
        for(i = 0;i < n;i++ ) {
            char c = word[i];
            if(ch == c) {
                break;
            }
        }
        if(i == n) return word;
        string temp = word.substr(0,i+1);
        string temp2 = word.substr(i+1);
        reverse(temp.begin(),temp.end());
        return temp+temp2;
    }
};