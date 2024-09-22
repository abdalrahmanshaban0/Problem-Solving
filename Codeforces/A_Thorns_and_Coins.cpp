/*
Problem Name : A. Thorns and Coins 
Author: Abdalrahman Shaban
Date: 21/02/2024 18:31:26
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
string s; 
int dp[55];
int rec(int idx){
    if(idx >= n){
        return 0;
    }
    int& ret = dp[idx];
    if(~ret) return ret;
    ret = 0;
    if(s[idx] =='@'){
        ret = 1 + max(rec(idx+1), rec(idx+2));
    }
    else if(s[idx] == '.'){
        ret = max(ret, max(rec(idx+1), rec(idx+2)));
    }
    return ret;
}

void solve(){
    cin >> n >> s; 
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
