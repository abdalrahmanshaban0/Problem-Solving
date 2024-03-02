/*
Problem Name : T - Bicoloring 
Author: Abdalrahman Shaban
Date: 02/03/2024 11:49:32
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


void dfs(int nd, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& clr, bool& ok){
    vis[nd] = 1;
    for(auto& child : adj[nd]){
        if(!vis[child]){
            clr[child] = !clr[nd];
            dfs(child, adj, vis, clr, ok);
        }
        if(clr[child] == clr[nd]){
            ok = 0;
            return;
        }
    }
}

void solve(){
    while(true){
        int n, e; cin >> n;
        if(!n) break;
        cin >> e;
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1);
        vector<int> clr(n+1);
        for(int i = 0; i < e; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ok = 1;
        for(int i = 0; i <= n; i++){
            if(!vis[i] && ok)
                dfs(i, adj, vis, clr, ok);
        }
        if(ok){
            cout << "BICOLORABLE.\n";
        }
        else{
            cout << "NOT BICOLORABLE.\n";
        }
    }
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
