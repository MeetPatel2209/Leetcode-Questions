class Solution {
public:
    int subarray(vector<int>&nums, int  k){
         int i=0,j=0,count=0,sum=0;
        while(j<nums.size()){
            if(nums[j]%2!=0) count++;
           
            while(count>k){
                if(nums[i]%2!=0) count--;
                i++;
            }
            
                sum+=j-i+1;

            
            j++;
        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1);
       
    }
};