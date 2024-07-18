/*
Problem Name : P - Cyclic Components 
Author: Abdalrahman Shaban
Date: 16/07/2024 13:57:57
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

int n, m;
vector<int>* adj;
vector<bool> vis;

int ok = -1;
void rec(int nd, int p){
    vis[nd] = 1;
    if(adj[nd].size() > 2) ok = 0;
    for(auto& ch : adj[nd]){
        if(!vis[ch]){
            rec(ch,nd);
        }
        else if(ch != p && ok == -1){
            ok = 1;
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = new vector<int>[n];
    vis.resize(n);

    for(int i = 0 ;i < m; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 0 ;i < n; i++){
        if(!vis[i]){
            ok = -1;
            rec(i,i);
            ans += (ok == 1);
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
