/*
Problem Name : C. Find B 
Author: Abdalrahman Shaban
Date: 24/02/2024 10:27:37
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
    int n, q; cin >> n >> q;
    vi v(n), prf1(n), prf2(n);
    for(int i = 0 ;i < n; i++){
        cin >> v[i];
        prf1[i] = v[i];
        if(v[i] == 1) prf2[i] = 2;
        else prf2[i] = 1;
    }
    for(int i = 1; i < n; i++){
        prf1[i] += prf1[i-1];        
        prf2[i] += prf2[i-1];
    }
    while(q--){
        int l, r; cin >> l >> r;
        if(l == r){
            NO;
        }
        else{
            ll sm1 = 0, sm2 = 0;
            if(l == 1){
                sm1 = prf1[r-1];
                sm2 = prf2[r-1];
            }
            else{
                l--, r--;
                sm1 = prf1[r] - prf1[l-1];
                sm2 = prf2[r] - prf2[l-1];
            }
            if(sm2 <= sm1) YES;
            else NO;
        }
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
