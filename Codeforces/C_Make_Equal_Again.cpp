/*
Problem Name : C. Make Equal Again 
Author: Abdalrahman Shaban
Date: 13/02/2024 16:53:58
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
    vi v(n);
    for(auto& i : v){
        cin >> i;
    }
    int l = 0, r = n-1;
    int cnt = n;
    while(l+1 < n){
        if(v[l] == v[l+1]){
            l++;
        } else break;
    }
    while(r >= 1){
        if(v[r] == v[r-1]){
            r--;
        } else break;
    }
    if(v[r] == v[l]){
        cout << max(0, r-l-1) << endl;
    }
    else{
        cout << max(0, min(r, n-l-1)) << endl;
    }
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
