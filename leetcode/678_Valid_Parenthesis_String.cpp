/*
Problem Name : 678. Valid Parenthesis String 
Author: Abdalrahman Shaban
Date: 08/04/2024 14:13:01
*/
class Solution {
private:
    int dp[101][101];
    bool rec(string& s, int idx, int opn){
        if(idx == s.size()){
            if(opn == 0) return true;
            return false;
        }
        int& ok = dp[idx][opn];
        if(~ok){
            return ok;
        }
        ok = 0;
        if(s[idx] == '*'){
            ok |= rec(s, idx+1, opn+1);
            if(opn-1 >= 0)
                ok |= rec(s, idx+1, opn-1);
            ok |= rec(s, idx+1, opn);
        }
        else{
            if(s[idx] == '(') opn++;
            else opn--;
            if(opn >= 0)
                ok |= rec(s, idx+1, opn);
        }
        return ok;
    }
public:
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return rec(s, 0, 0);
    }
};
