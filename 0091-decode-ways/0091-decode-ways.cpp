class Solution {
public:
    int waysDeco(string s,int n,int index,vector<int> &dp) {
        if(index == s.size()) {
            return 1;
        }
        if(s[index] == '0') {
            return 0;
        }
        if(index == s.size()-1) {
            return 1;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        string b = s.substr(index,2);
        int way1 = waysDeco(s,n,index+1,dp);
        int way2=0;
        if(stoi(b)<=26 && stoi(b)>0) {
            way2= waysDeco(s,n,index+2,dp);
        }
        return dp[index] = way1+way2;
    }
    int tabu(string s,int n) {
        vector<int> dp(s.size()+1);
        dp[0]=1;
        if(s[0]=='0')dp[1]=0;
        else dp[1]=1;
        for(int i=2;i<=s.size();i++){
            int way1,way2;
            if(s[i-1]=='0')way1=0;
            else way1=dp[i-1];
            if(stoi(s.substr(i-2,2))<=26&&stoi(s.substr(i-2,2))>0&&s[i-2]!='0')way2=dp[i-2];
            else way2=0;
            dp[i]=way1+way2;
        }
        return dp[s.size()];
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        //return waysDeco(s,n,0,dp);
        return tabu(s,n);   
    }
};