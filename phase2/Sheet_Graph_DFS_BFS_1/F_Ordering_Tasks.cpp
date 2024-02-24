/*
Problem Name : F - Ordering Tasks 
Author: Abdalrahman Shaban
Date: 24/02/2024 12:15:29
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

vector<vector<int>> adjList(101);
bool vis[101];
vector<int> ans;

void dfs(int nd){
    vis[nd] = 1;
    for(auto& child : adjList[nd]){
        if(!vis[child]){
            dfs(child);
        }
    }
    ans.push_back(nd);
}

void solve(){
    int n, m; 
    while(cin >> n >> m){
        if(!n)  break;
        memset(vis, 0, sizeof(vis));
        for(int i = 0 ;i < m; i++){
            int a, b; cin >> a >> b;
            adjList[a].push_back(b);
        }
        for(int i = 1; i <= n ;i++){
            if(!vis[i])
                dfs(i);
        }
        reverse(all(ans));
        for(int i = 0 ; i < ans.size(); i++){
            cout << ans[i];
            if(i < ans.size()-1) cout << ' ';
        } cout << endl;
        ans.clear();  adjList.clear(); adjList.resize(101);
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
