/*
Problem Name : 2108. Find First Palindromic String in the Array 
Author: Abdalrahman Shaban
Date: 13/02/2024 16:19:12
*/
class Solution {
public:
    bool ispal(string s){
        for(int i = 0; i < s.size()/2; i++){
            if(s[i]!=s[s.size()-1-i]) return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto& i : words){
            if(ispal(i)) return i;
        }
        return "";
    }
};
