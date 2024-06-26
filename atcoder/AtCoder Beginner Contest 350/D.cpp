/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 20/04/2024 14:23:12
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
    cin.tie(NULL);
    cout.tie(NULL);
}

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};


void dfs(vector<vector<int>>& adj, vector<bool>& vis, int nd, ll& nodes){
    vis[nd] = 1;
    nodes++;
    for(auto& child : adj[nd]){
        if(!vis[child]){
            dfs(adj, vis, child, nodes);
        }
    }
}

void solve(){
    int n, e; cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1);
    ll ans = -e;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ll nodes = 0;
            dfs(adj, vis, i, nodes);
            ans += (nodes*(nodes-1)/2);
        }
    }
    cout << ans ;
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
