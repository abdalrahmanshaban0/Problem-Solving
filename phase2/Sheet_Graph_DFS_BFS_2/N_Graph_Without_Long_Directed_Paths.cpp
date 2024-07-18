/*
Problem Name : N 
Author: Abdalrahman Shaban
Date: 17/07/2024 08:32:51
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

int n, m; 
vector<vector<int>> adj;
vector<bool> col, vis;

bool rec(int nd){
    vis[nd] = 1;
    bool ok = 1;
    for(auto& ch : adj[nd]){
        if(!vis[ch]){
            col[ch] = !col[nd];
            if(!rec(ch)) ok = 0;
        }
        else{
            if(col[ch] == col[nd]){
                return 0;
            }
        }
    }
    return ok;
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    col.resize(n);
    vis.resize(n);
    pair<int,int> arr[m];
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        --u, --v;
        arr[i] = {u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            col[i] = 0;
            ok &= rec(i);
        }
    }
    if(!ok){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        for(int i = 0 ;i < m; i++){
            if(col[arr[i].first] == 0 && col[arr[i].second] == 1){
                cout << 0;
            }
            else{
                cout << 1;
            }
        }
    }

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
