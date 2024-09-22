/*
Problem Name : B. Non-square Equation 
Author: Abdalrahman Shaban
Date: 16/02/2024 15:41:28
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

ll smdgt(ll num){
    ll sm = 0;
    while(num){
        sm += num % 10;
        num /= 10;
    }
    return sm;
}

void solve(){
    ll c; cin >> c;
    ll mx = (1+(int)log10(c))*9;
    ll ans = 1e10;
    for(ll i = 1; i <= mx; i++){
        ll tmp = i*i+4*c;
        ll hh = sqrt(tmp);
        if(hh * hh != tmp) continue;

        ll x1 = (-i + sqrt(tmp));
        ll x2 = (-i - sqrt(tmp));

        if(x1 > 0 && x1 % 2 == 0 && smdgt(x1/2) == i){
            ans = min(ans, x1/2);
        }
        if(x2 > 0 && x2 % 2 == 0 && smdgt(x2/2) == i){
            ans = min(ans, x2/2);
        }
    }
    cout << (ans == 1e10 ? -1 : ans);
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
