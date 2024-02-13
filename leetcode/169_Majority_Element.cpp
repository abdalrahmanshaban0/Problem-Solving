/*
Problem Name : 169. Majority Element 
Author: Abdalrahman Shaban
Date: 12/02/2024 15:21:43
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(auto& i : nums){
            mp[i]++;
            if(mp[i] > nums.size()/2) return i;
        }
        return -1;
    }
};
