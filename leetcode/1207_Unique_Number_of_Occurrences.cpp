/*
Problem Name : 1207. Unique Number of Occurrences 
Author: Abdalrahman Shaban
Date: 17/01/2024 10:53:53
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto& i : arr) mp[i]++;
        unordered_set<int> st;
        for(auto& i : mp){
            st.insert(i.second);
        }
        return st.size() == mp.size();
    }
};
