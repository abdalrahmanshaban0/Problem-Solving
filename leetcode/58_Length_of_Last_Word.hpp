/*
Problem Name : 58. Length of Last Word 
Author: Abdalrahman Shaban
Date: 01/04/2024 02:28:51
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' ') cnt++;
            else if(cnt) return cnt;
        }
        return cnt;
    }
};
