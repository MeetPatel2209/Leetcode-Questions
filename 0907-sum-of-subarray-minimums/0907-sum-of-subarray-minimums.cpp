class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int left[n];
        int right[n];
        stack<int> s;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int key = arr[i];
            while(!s.empty() && arr[s.top()] > key)
            {
                s.pop();
            }
            left[i] = (s.empty())?0:s.top()+1;
            s.push(i);
        }
        while(!s.empty())
        {
            s.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            int key=arr[i];
            while(!s.empty() && arr[s.top()]>=key)
            {
                s.pop();
            }
            right[i]=(s.empty())?n-1:s.top()-1;
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            long long a=(arr[i]*(i-left[i]+1))%1000000007;
            a=(a*(right[i]-i+1))%1000000007;
            ans+=a;
            ans%=1000000007;
        }
        return ans;
    }
};