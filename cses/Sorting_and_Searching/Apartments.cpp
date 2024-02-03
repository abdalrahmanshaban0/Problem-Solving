/*
Problem Name : Apartments 
Author: Abdalrahman Shaban
Date: 02/02/2024 19:57:16
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
    int n, m; ll k; cin >> n >> m >> k;
    multiset<ll> d; multiset<ll> st;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        d.insert(x);
    }
    for(int i = 0 ; i < m; i++){
        ll x; cin >> x;
        st.insert(x);
    }
    ll ans = 0;
    for(auto& i : st){
        auto it = d.lower_bound(i-k);
        if(it == d.end()) it--;
        if(abs(*it-i) <= k){
            ans++;
            d.erase(it);
        }
    } 
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
