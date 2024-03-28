/*
Problem Name : 2958. Length of Longest Subarray With at Most K Frequency 
Author: Abdalrahman Shaban
Date: 28/03/2024 19:33:35
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = -1;
        int ans = 0;
        while(++r < n){
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
