/*
Problem Name : 2225. Find Players With Zero or One Losses 
Author: Abdalrahman Shaban
Date: 15/01/2024 20:03:37
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        set<int> winers, losers;
        for(auto& i : matches){
            losses[i[1]]++;
        }
        for(auto& i : matches){
            int chk = losses[i[1]];
            if(chk == 1){
                losers.insert(i[1]);
            }
            if(!losses.count(i[0])){
                winers.insert(i[0]);
            }
        }
        vector<int> temp1(winers.begin(), winers.end());
        vector<int> temp2(losers.begin(), losers.end());
        return {temp1, temp2};
    }
};

