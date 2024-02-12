/*
Problem Name : Grid Paths 
Author: Abdalrahman Shaban
Date: 09/02/2024 15:22:36
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

void solve(){
    int n; cin >> n;
    char arr[n+1][n+1];
    for(int i = 1 ;i <= n ;i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    if(arr[n][n] != '*')
        dp[n][n] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if(i == n && j == n) continue;
            if(arr[i][j] != '*'){
                if(i+1 <= n)
                    dp[i][j] += dp[i+1][j];
                if(j+1 <= n)
                    dp[i][j] += dp[i][j+1];
                dp[i][j] %= MOD;
            }

        }
    }
    cout << dp[1][1];
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
