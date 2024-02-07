/*
Problem Name : D. Essa's Goal 
Author: Abdalrahman Shaban
Date: 05/02/2024 22:20:24
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
    vector<pair<ll, ll>> v(n);
    map<ll, ll> mp;
    ll sm = 0;
    for(int i = 0; i < n ; i++){
        cin >> v[i].first >> v[i].second;
        mp[v[i].second] += v[i].first;
        sm += v[i].first;
    }
    int m ; cin >> m;
    vi frq(m+1,0);
    for(auto& i : mp){
        for(int j = i.first+1; j <= m ; j += i.first+1){
            frq[j] += i.second;
        }
    }
    frq[0] = sm;
    sm = 0;
    for(int i = 0; i < m ;i++){
        ll cc; cin >> cc;
        sm += frq[i];
        if(cc > sm){
            cout << "No";
            return;
        }
        else{
            sm -= cc;
        }
    }
    cout << "Yes";
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
