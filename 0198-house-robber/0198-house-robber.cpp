class Solution {
public:
    
    int countHouse(vector<int> nums, int n,int arr[])
    {
    if(n<=0)
        return 0;
    if(n==1)
        return nums[0];
    if(n==2)
        return max(nums[0],nums[1]);

    if(arr[n] !=-1)
        return arr[n];
    return arr[n] = max(nums[n-1]+countHouse(nums,n-2,arr), nums[n-2]+countHouse(nums,n-3,arr));
    }

    int rob(vector<int>& nums) {
        int arr[101];
        memset(arr,-1,sizeof(arr));
        int n=nums.size();
        int ans = countHouse(nums,n,arr);
        return ans;
    }
};