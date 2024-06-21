class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto word : wordList) st.insert(word);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            if(temp.first == endWord) return temp.second;
            string word = temp.first;
            int level = temp.second;
            for(int i=0;i<word.size();i++) {
                for(char j = 'a';j<='z';j++) {
                    if(j == word[i]) continue;
                    string temp = word;
                    temp[i] = j;
                    if(st.find(temp) != st.end()) {
                        st.erase(temp);
                        q.push({temp,level+1});
                    }
                }
            }
        }
        return 0;
    }
};