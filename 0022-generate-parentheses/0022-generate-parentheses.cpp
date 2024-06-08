class Solution {
public:
    void generate(int start,int end,string ans,vector<string> &final,int n)
    {
        if(start==n)
        {
            if(end==n)
            {
                cout << ans<< " ";
                final.push_back(ans);
            }
            else
            {
                while(end!=n)
                {
                    ans.push_back(')');
                    end++;
                }
                cout << ans << " ";
                final.push_back(ans);
            }
            return;
        }
        if(start>end)
        {
            ans.push_back(')');
            generate(start,end+1,ans,final,n);
            ans.pop_back();
        }
        ans.push_back('(');
        generate(start+1,end,ans,final,n);
        ans.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string ans="";
        vector<string> final;
        generate(0,0,ans,final,n);
        return final;
    }
};