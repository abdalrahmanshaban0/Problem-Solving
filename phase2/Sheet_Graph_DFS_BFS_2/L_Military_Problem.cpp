/*
Problem Name : L - Military Problem 
Author: Abdalrahman Shaban
Date: 16/07/2024 02:55:49
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

int n, q;
vector<vector<int>> adj;
vector<int> dp;

void dfs(int u, int p, vector<int>& topo){
    dp[u] = 1;
    for(auto& v : adj[u]){
        if(v != p) dfs(v,u,topo), dp[u] += dp[v];
    }
    topo.push_back(u);
}

void solve(){
    cin >> n >> q;
    adj.resize(n+1);
    dp.resize(n+1);
    for(int i = 2; i <= n ;i++){
        int of; cin >> of;
        adj[of].push_back(i);
    }
    for(int i = 1; i <= n; i++) reverse(adj[i].begin(), adj[i].end());

    vector<int> topo;
    dfs(1,1,topo);
    reverse(topo.begin(),topo.end());
    map<int,int> idx;
    for(int i = 0; i < topo.size(); i++) idx[topo[i]] = i;

    while(q--){
        int of, k; cin >> of >> k; 
        if(k > dp[of]){
            cout << -1;
        }
        else{
            cout << topo[idx[of]+k-1];
        }
        cout << endl;
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
