class Solution {
public:
    
    void getComb(int k,int n,vector<vector<int>> &res,vector<int> temp,vector<int> nums,int index) {
        if(n == 0) {
            if(temp.size() == k) {
                res.push_back(temp);
            }
            return;
        }
        if(index == 9) {
            return;
        }
        if(nums[index]<=n) {
            temp.push_back(nums[index]);
            getComb(k,n-nums[index],res,temp,nums,index+1);
            temp.pop_back();
        }
        getComb(k,n,res,temp,nums,index+1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> nums(9);
        for(int i=0;i<9;i++) {
            nums[i]=i+1;
        }
        getComb(k,n,res,temp,nums,0);
        return res;
    }
};