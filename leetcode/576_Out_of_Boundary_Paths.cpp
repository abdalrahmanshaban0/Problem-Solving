/*
Problem Name : 576. Out of Boundary Paths 
Author: Abdalrahman Shaban
Date: 26/01/2024 16:14:00
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define clr(arr, x) (memset(arr, x, sizeof arr))
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<ll>
const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    long long dp[51][51][51];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int modo = 1e9+7;
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    bool isout(int i, int j, int n, int m){
        return(i >= n || j >= m || i < 0 || j < 0);
    }
    long long rec(int i, int j, int stps, int n, int m){        
        if(stps == 0){
            return 0;
        }
        long long& ret = dp[i][j][stps];
        if(~ret){
            return ret;
        }
        ret = 0;
        for(int k = 0; k < 4; k++){
            if(isout(i+dx[k], j+dy[k], n, m)){
                ret++;
            }
            else{
                ret += rec(i+dx[k], j+dy[k], stps-1, n, m);
            }
        }
        return ret%=modo;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return rec(startRow, startColumn, maxMove, m, n);
    }
};

void solve(){

}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
