/*
Problem Name : D. Three Activities 
Author: Abdalrahman Shaban
Date: 11/02/2024 23:26:52
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

ll rec(int i, vector<bool>& vis, vector<vector<ll>>& v, vector<vector<ll>>& vv){
    if(i == 3){
        return 0;
    }
    ll ret = 0;
    for(int h = 0; h < 3; h++){
        if(!vis[vv[i][h]]){
            vis[vv[i][h]] = 1;
            ret = max(ret, v[i][vv[i][h]] + rec(i+1, vis, v, vv));
            vis[vv[i][h]] = 0;
        }
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<vector<ll>> v(3, vector<ll>(n));
    vector<vector<ll>> vv(3);
    for(int i = 0; i < 3; i++){
        vector<ll> tmp;
        priority_queue<pair<ll, int>> pr;
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            pr.push({v[i][j], j});
        }
        for(int j = 0; j < 3; j++){
            tmp.push_back(pr.top().second);
            pr.pop();
        }
        vv[i] = tmp;
    }

    vector<bool> vis(n+1, 0);
    cout << rec(0, vis, v, vv) << endl;
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
