/*
Problem Name : R - Tree Cutting (Easy Version) 
Author: Abdalrahman Shaban
Date: 17/07/2024 23:15:26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

int n;
vector<int> *adj, col;
vector<bool> vis;
vector<pair<int,int>> v;

void dfs(int nd,int p){
    vis[nd] = 1;
    v[nd].first += (col[nd]==1);
    v[nd].second += (col[nd]==2);
    for(auto& ch : adj[nd]){
        if(ch != p){
            dfs(ch,nd);
            v[nd].first += v[ch].first;
            v[nd].second += v[ch].second;
        }
    }
}

void solve(){
    cin >> n;
    adj = new vector<int>[n];
    col.resize(n);
    vis.resize(n);
    v.resize(n);
    vector<pair<int,int>> edgs;
    int r = 0, b = 0;
    for(int i = 0; i < n; i++){
        cin >> col[i];
        r += (col[i]==1);
        b += (col[i]==2);
    }
    for(int i = 0; i+1 < n; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i].first == 0 && v[i].second == b ||
                v[i].first == r && v[i].second == 0){
            ans++;
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
