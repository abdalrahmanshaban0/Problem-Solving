/*
Problem Name : 287. Find the Duplicate Number 
Author: Abdalrahman Shaban
Date: 24/03/2024 22:00:20
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = 1e6;
        int frq[N] = {};
        for(auto& i : nums){
            frq[i]++;
            if(frq[i] > 1) return i;
        }
        return -1;
    }
};
