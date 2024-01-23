class Solution {
public:
    vector<int> chCnt;
    int charCnt[16][26];
    bool check(string s) {
        int n = s.size();
        vector<int> count(26,0);
        for(int i=0;i<n;i++) {
            if(count[s[i]-'a'] == 1 || chCnt[s[i]-'a'] == 1) {
                return false;
            }
            count[s[i]-'a']=1;
        }
        return true;
    }

    int getMax(vector<string> &arr,int index) {
        if(index == arr.size()) {
            return 0;
        }
        int notTake = getMax(arr,index+1);
        int take = 0;
        if(check(arr[index])) {
            for(int i=0;i<arr[index].size();i++) {
                chCnt[arr[index][i]-'a'] = charCnt[index][arr[index][i]-'a'];
            }
            take = (int)arr[index].size() + getMax(arr,index+1);
            for(int i=0;i<arr[index].size();i++) {
                chCnt[arr[index][i]-'a'] = 0;
            }
        }
        return max(take,notTake);
    }

    int maxLength(vector<string>& arr) {
        chCnt.resize(26,0);
        for(int i=0;i<16;i++) {
            for(int j=0;j<26;j++) {
                charCnt[i][j] = 0;
            }
        }
        for(int j=0;j<arr.size();j++) {
            int n = arr[j].size();
            for(int i=0;i<n;i++) {
                charCnt[j][arr[j][i]-'a'] = 1;
            }
        }
        return getMax(arr,0);
    }
};