/*
Problem Name : F 
Author: Abdalrahman Shaban
Date: 28/03/2024 21:02:10
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

void bld(vector<vector<int>>& adj, int a, int b, int nod){
    for(int i = 0; i < adj.size(); i++){
        if(adj[i].empty()){
            if(a){
                adj[i].push_back(++nod);
                adj[i].push_back(++nod);
                a--;
            }
            else if(b){
                adj[i].push_back(++nod);
                b--;
            }
        }
    }
}

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int nd, int ln, int& h){
    vis[nd] = 1;
    h = max(h, ln);
    for(auto& child : adj[nd]){
        if(!vis[child]){
            dfs(adj, vis, child, ln+1, h);
        }
    }
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    vector<vector<int>> adj(2*a+1+b);
    bld(adj, a, b, 0);
    int chk = 0;
    for(int i = 0; i < adj.size(); i++){
        if(adj[i].empty()) chk++;
    } 
    
    if(chk != c){
        cout << -1 << endl; return;
    }
    else{
        vector<bool> vis(adj.size());
        int height = 0;
        dfs(adj, vis, 0, 0, height);
        cout << height << endl;
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
