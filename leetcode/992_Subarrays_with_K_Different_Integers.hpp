/*
Problem Name : 992. Subarrays with K Different Integers 
Author: Abdalrahman Shaban
Date: 01/04/2024 02:29:20
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l1 = 0, l2 = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(; r < n; r++){
            mp[nums[r]]++;
            if(mp.size() > k){
                while(mp.size() > k){
                    mp[nums[l2]]--;
                    if(!mp[nums[l2]]) mp.erase(nums[l2]);
                    l2++;
                }
                l1 = l2;
            }
            if(mp.size() == k){
                while(mp[nums[l2]] > 1) mp[nums[l2++]]--;
                ans += l2-l1+1;
            }
        }
        return ans;
    }
};
