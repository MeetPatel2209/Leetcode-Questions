class Solution {
public:
    
    void generate(int n,int k,vector<int> candidates,int index,vector<int> temp,vector<vector<int>> &ans,int sum) {
        if(sum == k) {
            ans.push_back(temp);
            return;
        }
        if(index == n || sum > k) return;
        
        temp.push_back(candidates[index]);
        sum += candidates[index];
        generate(n,k,candidates,index,temp,ans,sum);
        sum -= candidates[index];
        temp.pop_back();
        generate(n,k,candidates,index+1,temp,ans,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        int n = candidates.size();
        generate(n,target,candidates,0,temp,ans,sum);
        return ans;
    }
};