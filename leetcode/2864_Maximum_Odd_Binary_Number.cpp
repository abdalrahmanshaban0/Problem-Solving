/*
Problem Name : 2864. Maximum Odd Binary Number 
Author: Abdalrahman Shaban
Date: 01/03/2024 08:39:48
*/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int ans = 0;
        for(int i = 0; i+1 < s.size(); i++){
            if(ones > 1){
                s[i] = '1';
                ones--;
            }
            else{
                s[i] = '0';
            }
        }
        s[s.size()-1] = '1';
        return s;
    }
};
