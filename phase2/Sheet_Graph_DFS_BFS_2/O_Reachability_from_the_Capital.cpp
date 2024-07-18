/*
Problem Name : O - Reachability from the Capital 
Author: Abdalrahman Shaban
Date: 16/07/2024 12:40:32
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

int n, m, c;
vector<vector<int>> adj;

int dfs(int nd, vector<bool>& vis){
    vis[nd] = 1;
    int ret = 1;
    for(auto& ch : adj[nd]){
        if(!vis[ch]){
            ret += dfs(ch,vis);
        }
    }
    return ret;
}

void solve(){
    cin >> n >> m >> c;
    adj.resize(n+1);
    for(int i = 0; i < m ;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<bool> vis1(n+1), vis2(n+1);
    dfs(c,vis1);
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            int val = dfs(i,vis2);
            v.push_back({val,i});
            vis2.clear(); vis2.resize(n+1);
        }
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(auto& [a,b]:v){
        if(!vis1[b]){
            ans++;
            dfs(b,vis1);
        }
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve(); 

    return 0;
}


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
