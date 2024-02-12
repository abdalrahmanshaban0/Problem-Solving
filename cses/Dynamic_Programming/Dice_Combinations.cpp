/*
Problem Name : Dice Combinations 
Author: Abdalrahman Shaban
Date: 08/02/2024 23:28:11
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

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

const int N = 1e6+1;
ll dp[N];
ll rec(ll rem){
    if(rem == 0){
        return 1LL;
    }
    ll& ans = dp[rem];
    if(~ans) return ans;
    ans = 0;
    for(int i = 1; i <= 6; i++){
        if(i <= rem){
            ans += rec(rem - i);
            ans %= MOD;
        }
    }
    return ans;
}

void solve(){
//    memset(dp, -1, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    ll n; cin >> n;
//    cout << rec(n);
    dp[0] = 1;    
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= 6; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n];
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
