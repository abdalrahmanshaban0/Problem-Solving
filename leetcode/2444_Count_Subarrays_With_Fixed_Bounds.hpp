/*
Problem Name : 2444. Count Subarrays With Fixed Bounds 
Author: Abdalrahman Shaban
Date: 01/04/2024 02:30:18
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mnk, int mxk) {
        int n = nums.size();
        int r = 0, l = 0, mnidx = -1, mxidx = -1;
        long long ans = 0;
        for(; r < n; r++){            
            if(nums[r] > mxk || nums[r] < mnk){
                l = r+1;
                mnidx = mxidx = -1;
            }
            else{
                if(nums[r] == mnk) mnidx = r;
                if(nums[r] == mxk) mxidx = r;
                if(~mnidx && ~mxidx)
                    ans += min(mnidx, mxidx)-l+1;
            }
        }
        return ans;
    }
};
