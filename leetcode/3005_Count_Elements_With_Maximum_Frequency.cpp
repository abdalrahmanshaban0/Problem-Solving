/*
Problem Name : 3005. Count Elements With Maximum Frequency 
Author: Abdalrahman Shaban
Date: 08/03/2024 11:39:50
*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
        map<int, int> mp;
        int mxfrq = 0;
        for(auto& i : v){
            mp[i]++;
            mxfrq = max(mxfrq, mp[i]);
        }
        int cnt = 0;
        for(auto& i : v){
            if(mp[i] == mxfrq){
                cnt++;
            }
        }
        return cnt;
    }
};
