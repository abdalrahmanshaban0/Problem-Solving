/*
Problem Name : Two Sets II 
Author: Abdalrahman Shaban
Date: 09/02/2024 22:25:06
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

int n;
int dp[500][250000];
ll ans;
ll sm;
int rec(int idx, int sm1){
    if(idx == n){
        if(sm % 2 == 0 && sm1+idx == sm/2){
            return 1;
        }
        return 0;
    }
    int& ret = dp[idx][sm1];
    if(~ret) return ret;
    ret = 0;
    ret += rec(idx+1, sm1+idx);
    ret %=MOD;
    ret +=rec(idx+1, sm1);
    ret %= MOD;
    return ret;
}

void solve(){
    cin >> n;
    sm = n*(n+1)/2;
    memset(dp, -1, sizeof(dp));
    cout << rec(1, 0);
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
