/*
Problem Name : F 
Author: Abdalrahman Shaban
Date: 09/04/2024 22:42:02
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
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[201][201][201];
bool bob(int a, int b, int c){
    if((a+c)&1) return 0;
    if((a+b)&1) return 0;
    if((b+c)&1) return 0;
    return 1;
}
int getmx(int a, int b, int c){
    if(a+b+c == 0) return 0;
    int& ret = dp[a][b][c];
    if(~ret) return ret;
    bool chk = bob(a, b, c);
    ret = chk;
    if(a){
        ret = max(ret, chk + getmx(a-1, b, c));
    }
    if(b){
        ret = max(ret, chk + getmx(a, b-1, c));
    }
    if(c){
        ret = max(ret, chk + getmx(a, b, c-1));
    }
    return ret;
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = getmx(a, b, c) + d/2;
    cout << ans << endl;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        solve();
    }
    return 0;
}
