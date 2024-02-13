class Solution {
public:
    
    bool checkPalindrome(string word) {
        string temp = word;
        reverse(temp.begin(),temp.end());
        if(temp == word) return true;
        return false;
    }
    
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(auto word : words) {
            if(checkPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};