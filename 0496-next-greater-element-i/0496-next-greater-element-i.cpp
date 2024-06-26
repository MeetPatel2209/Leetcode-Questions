class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> ump;
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            ump[nums2[i]] = (st.empty() ? -1 : st.top());
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++) {
            nums1[i] = ump[nums1[i]];
        }
        return nums1;
    }
};