/*
Problem Name : 791. Custom Sort String 
Author: Abdalrahman Shaban
Date: 11/03/2024 18:43:30
*/
class Solution {
public:
    string customSortString(string order, string s) {
        int frq[26] = {};
        for(auto& i : s){
            frq[i-'a']++;
        }
        string ans;
        for(auto& i : order){
            while(frq[i-'a']){
                ans += i;
                frq[i-'a']--;
            }
        }
        for(int i = 0; i < 26; i++){
            while(frq[i]){
                ans += (i+'a');
                frq[i]--;
            }
        }
        return ans;
    }
};
