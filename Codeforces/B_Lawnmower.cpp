/*
Problem Name : B. Lawnmower 
Author: Abdalrahman Shaban
Date: 02/02/2024 20:36:26
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef vector<string> si;
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
    int n, m; cin >> n >> m;
    si v(n);
    vector<int> L(n, -1), R(n, -1);
    int lstidx = 0;
    for(int i = 0; i < n ;i++){
        cin >> v[i];
        for(int j = 0; j < m; j++) if(v[i][j] == 'W'){
            if(R[i] == -1){
                L[i] = j;
            }
            R[i] = j;
        }
        if(~R[i]) lstidx = i;
    }
    n = lstidx+1;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n ;i++){
        int l = 0, r = 0;
        int nxt = cur;
        if(i%2 == 0){
            if(R[i]>=0){
                nxt = max(nxt, R[i]);
            }
            if(i+1 < n && R[i+1] >= 0){
                nxt = max(nxt, R[i+1]);
            }
        }
        else{
            if(L[i] >= 0){
                nxt = min(nxt, L[i]);
            } 
            if(i+1 < n && L[i+1] >= 0){
                nxt = min(nxt, L[i+1]);
            }
        }
        ans += abs(nxt-cur);
        if(i+1 < n) ans++;
        cur = nxt;
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
