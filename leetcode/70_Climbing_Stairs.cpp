/*
Problem Name : 70. Climbing Stairs 
Author: Abdalrahman Shaban
Date: 18/01/2024 15:20:17
*/
class Solution {
public:
    const static int N = 46;
    int dp[N];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int rec(int i, int n){
        if(i == n){
            return 1;
        }
        else if(i > n){
            return 0;
        }
        if(~dp[i]) return dp[i];
        return dp[i] = (rec(i+1, n) + rec(i+2, n));
    }
    int climbStairs(int n) {
        return rec(0, n); 
    }
};
