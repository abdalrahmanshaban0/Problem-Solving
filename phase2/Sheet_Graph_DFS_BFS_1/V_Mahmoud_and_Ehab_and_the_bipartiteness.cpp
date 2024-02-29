/*
Problem Name : V - Mahmoud and Ehab and the bipartiteness 
Author: Abdalrahman Shaban
Date: 29/02/2024 21:29:20
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

const int N = 1e5+1;
vector<vector<int>> adj(N);
vector<bool> vis(N);
vector<int> clr(N);

void dfs(int nd, int c){
    vis[nd] = 1;
    clr[nd] = c;
    for(auto& child : adj[nd]){
        if(!vis[child]){
            dfs(child, !c);
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0 ;i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll os = 0, zs = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            clr[i] = 1;
            dfs(i, 0);
        }
        if(clr[i] == 0) zs++;
        else if(clr[i] == 1) os++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(clr[i] == 0){
            ans += abs((ll)adj[i].size()-os);
        }
    }
    cout << ans;
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
