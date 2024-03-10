/*
Problem Name : 349. Intersection of Two Arrays 
Author: Abdalrahman Shaban
Date: 10/03/2024 15:50:28
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        set<int> st;
        for(auto& i : nums1) mp[i]++;
        for(auto& i : nums2){
            if(mp[i]){
                st.insert(i);
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
