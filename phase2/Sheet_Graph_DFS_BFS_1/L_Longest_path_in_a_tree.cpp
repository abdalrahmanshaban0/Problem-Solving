/*
Problem Name : L - Longest path in a tree 
Author: Abdalrahman Shaban
Date: 24/02/2024 13:03:47
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
vector<vector<int>> adjList(10001);
vector<int> vis(10001);

int mx = 0, mxnd = 0;

void dfs(int nd, int ln){
    vis[nd] = 1;
    if(mx < ln){
        mx = ln;
        mxnd = nd;
    }
    for(auto& i : adjList[nd]){
        if(!vis[i]){
            dfs(i, ln+1);
        }
    }
}


void solve(){
    int n; cin >> n; 
    for(int i = 1 ;i < n; i++){
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, 0);
    vis.clear(); vis.resize(10001);
    mx = 0;
    dfs(mxnd, 0);
    
    cout << mx;
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
