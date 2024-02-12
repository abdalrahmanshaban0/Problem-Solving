/*
Problem Name : Book Shop 
Author: Abdalrahman Shaban
Date: 09/02/2024 17:51:16
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
    int n, x; cin >> n >> x;
    int bprice[n], bpaper[n];
    for(int i = 0 ;i < n; i++) cin >> bprice[i];
    for(int i = 0 ;i < n; i++) cin >> bpaper[i];
    int dp[2][x+1];
    memset(dp, 0, sizeof(dp));
    bool p = 0;
    for(int j = 0 ;j < n; j++){
        p = !p;
        for(int i = 1; i <= x; i++){
            dp[p][i] = dp[!p][i];
            if(i >= bprice[j]){
                dp[p][i] = max(dp[p][i], dp[!p][i-bprice[j]]+bpaper[j]);
            }
        }
    }
    cout << dp[p][x];
}

int main() {
    Fast();
    file();
    int t = 1;
//    cin >> t;
    while(t--){
        solve() ;
    }
    return 0;
}
