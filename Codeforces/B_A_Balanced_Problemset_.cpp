/*
Problem Name : B. A Balanced Problemset? 
Author: Abdalrahman Shaban
Date: 27/01/2024 17:01:43
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


void solve(){
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll ans = 1;
        for(ll i = 1; i*i <= n; i++){
            if(n % i == 0){
                if(n/i >= k)
                    ans = max(ans, i);
                if(n % (n/i) == 0 && n/(n/i) >= k){
                    ans = max(ans, n/i);
                }
            }
        } 
        cout << ans << '\n';
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
