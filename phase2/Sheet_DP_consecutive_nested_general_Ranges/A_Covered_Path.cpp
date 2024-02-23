/*
Problem Name : A - Covered Path 
Author: Abdalrahman Shaban
Date: 22/02/2024 09:01:45
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

int v1, v2, t, d;
int dp[101][10001];
int rec(int tm, int v){
    if(tm == t){
        if(v == v2){
            return v2;
        }
        return -1e9;
    }
    int& ret = dp[tm][v];
    if(~ret) return ret;
    ret = -1e9;
    for(int i = -d; i <= d; i++){
        ret = max(ret, v + rec(tm+1, v+i));
    }
    return ret;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> v1 >> v2 >> t >> d;
    cout << rec(1, v1);
}

int main() {
    Fast();
    file();
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
