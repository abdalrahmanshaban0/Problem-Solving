/*
Problem Name : Minimizing Coins 
Author: Abdalrahman Shaban
Date: 08/02/2024 23:58:40
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
    int n; ll x; cin >> n >> x;
    ll coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    const int N = 1e6+1;
    ll dp[N] = {};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(ll i = 1LL; i <= x; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < n; j++){
            if(i >= coins[j]){
                dp[i]= min(dp[i-coins[j]]+1, dp[i]);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}