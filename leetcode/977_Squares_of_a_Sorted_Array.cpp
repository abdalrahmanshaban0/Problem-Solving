/*
Problem Name : 977. Squares of a Sorted Array 
Author: Abdalrahman Shaban
Date: 02/03/2024 11:14:27
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& i : nums) i = i*i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
