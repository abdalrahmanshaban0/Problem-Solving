/*
Problem Name : 279. Perfect Squares 
Author: Abdalrahman Shaban
Date: 08/02/2024 14:09:20
*/
class Solution {
    public:
        int dp[9001];
        int rec(int rem){
            if(rem == 0){
                return 0;
            }
            int& ans = dp[rem];
            if(~ans) return ans;
            ans = INT_MAX;
            for(int i = 1; i*i <= rem; i++){
                ans = min(ans, 1 + rec(rem - i*i));
            }
            return ans;
        }
        int numSquares(int n) {
            memset(dp, -1, sizeof(dp));
            return rec(n);
        }
};
