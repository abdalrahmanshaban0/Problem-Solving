/*
Problem Name : U - Pick up sticks 
Author: Abdalrahman Shaban
Date: 29/04/2024 00:22:44
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


void solve(){
    int n, m;
    while(cin >> n >> m){
        if(!n){
            break; 
        }
        vector<int> fo(n+1);
        vector<vector<int>> adj(n+1);
        for(int i = 0 ;i < m; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            fo[b]++;
        }
        vector<bool> vis(n+1);
        vector<int> ans;
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(fo[i] == 0 && !vis[i]){
                queue<int> q; q.push(i);
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    vis[cur] = 1;
                    ans.push_back(cur);
                    for(auto& child : adj[cur]){
                        fo[child]--;
                        if(fo[child] == 0) q.push(child);
                    }
                }
            }
        }

        if(ans.size() != n){
            cout << "IMPOSSIBLE\n"; continue;        
        }
        for(auto& i : ans) cout << i << '\n';
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
