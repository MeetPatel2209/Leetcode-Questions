class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> ump;
        for(auto s : dictionary) {
            ump[s]++;
        }
        vector<string> words;
        string word = "";
        for(auto c : sentence) {
            if(c == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word = word + c;
            }
        }
        words.push_back(word);
        string res = "";
        string temp = "";
        for(auto word : words) {
            temp = "";
            int flag = 0;
            for(auto c : word) {
                temp = temp + c;
                if(ump.find(temp) != ump.end()) {
                    res = res + temp + " ";
                    flag = 1;
                    break;
                }
            }
            if(!flag) res = res + word + " ";
        }
        res.pop_back();
        return res;
    }
};