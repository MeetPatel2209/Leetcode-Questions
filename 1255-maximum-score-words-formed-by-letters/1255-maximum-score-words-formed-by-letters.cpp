class Solution {
public:
    int _compute(vector<int> points,int index,unordered_map<char,int> ump,vector<string>& words) {
        if(index == points.size()) {
            return 0;
        }
        int take = 0;
        int notTake = _compute(points,index+1,ump,words);
        unordered_map<char,int> temp;
        for(auto c : words[index]) temp[c]++;
        bool check = false;
        for(auto c : words[index]) {
            if(temp[c] > ump[c]) {
                check = true;
                break;
            }
        }
        unordered_map<char,int> temp2 = ump;
        if(!check) {
            for(auto c : words[index]) ump[c]--;
            take = points[index] + _compute(points,index+1,ump,words);
            for(auto c : words[index]) ump[c]=temp2[c];
        }
        return max(take,notTake);
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> points(n,0);
        for(int i=0;i<n;i++) {
            int temp = 0;
            string word = words[i];
            for(auto c : word) {
                temp+=score[c-'a'];
            }
            points[i] = temp;
        }
        unordered_map<char,int> ump;
        for(auto letter : letters) ump[letter]++;
        int ans = _compute(points,0,ump,words);
        return ans;
    }
};