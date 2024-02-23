/*
Problem Name : D - Forming Teams 
Author: Abdalrahman Shaban
Date: 22/02/2024 22:21:16
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

int n, e;
vector<vector<int>> adj(101);
vector<int> vis(101);
int cnt = 0;
bool dfs(int nd, int pr){
    if(vis[nd]){
        return 1;
    }
    vis[nd] = 1;
    for(auto& child : adj[nd]){
        if(child != pr){
            cnt++;
           if(dfs(child, nd)) return 1;
        }
    }
    return 0;
}

void solve(){
    cin >> n >> e;
    for(int i = 0 ;i < e; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cnt = 0;
        if(!vis[i]){
            bool cycle = dfs(i, -1);
            if(cycle){
                if(cnt & 1) ans++;
            }
        }
    }
    if((n-ans)&1) ans++;
    cout << ans;
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
