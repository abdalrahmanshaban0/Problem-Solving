/*
Problem Name : 387. First Unique Character in a String 
Author: Abdalrahman Shaban
Date: 05/02/2024 13:20:11
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int frq[26] = {};
        for(auto& i : s){
            frq[i-'a']++;
        }
        for(int i = 0; i < n; i++){
            if(frq[s[i]-'a']==1) return i;
        } 
        return -1;
    }
};
