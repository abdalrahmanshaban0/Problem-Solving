/*
Problem Name : 997. Find the Town Judge 
Author: Abdalrahman Shaban
Date: 22/02/2024 08:09:53
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, int> mp, mpp;
        for(auto& i : trust){
            mp[i[1]]++;
            mpp[i[0]]++;
        }
        for(auto& i : mp){
            if(i.second == n-1 && !mpp[i.first]){
                return i.first;
            }
        }
        if(mp.empty()){
            if(n != 1)
                return -1;
            else
                return 1;
        }
        return -1;
    }
};
