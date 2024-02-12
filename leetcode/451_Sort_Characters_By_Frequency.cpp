/*
Problem Name : 451. Sort Characters By Frequency 
Author: Abdalrahman Shaban
Date: 07/02/2024 16:56:05
*/
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        int frq[200] = {};
        for(auto& i : s) frq[i]++;
        vector<pair<int, char>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {frq[s[i]], s[i]};
        }
        sort(v.rbegin(), v.rend());
        string ans;
        for(auto& i : v) ans += i.second;
        return ans;
    }
};
