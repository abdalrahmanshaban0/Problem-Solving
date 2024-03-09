/*
Problem Name : 2540. Minimum Common Value 
Author: Abdalrahman Shaban
Date: 09/03/2024 12:31:22
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(auto& i : nums1) mp[i]++;
        int mn = INT_MAX;
        for(auto& i : nums2){
            if(mp[i]){
                mn = min(mn, i);
            }
        }
        return (mn == INT_MAX ? -1 : mn);
    }
};
