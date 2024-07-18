/*
Problem Name : M - Circular Dance 
Author: Abdalrahman Shaban
Date: 16/07/2024 01:05:09
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

vector<vector<int>> adj;
vector<bool> vis;
vector<int> topo;
void dfs(int nd){
    vis[nd] = 1;
    for(auto& ch : adj[nd]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
    topo.push_back(nd);
}

void solve(){
    int n; cin >> n;
    adj.resize(n);
    vis.resize(n);
    vector<pair<int,int>> v(n);
    for(int i = 0 ;i < n; i++){
        int a, b; cin >> a >> b; 
        --a, --b;
        v[i] = {a,b};
    }
    for(int i = 0 ;i < n ;i++){
        pair<int,int> a = v[i];
        pair<int,int> b = v[a.first];
        pair<int,int> c = v[a.second];
        set<int> st = {a.first,a.second,b.first,b.second};
        if(st.size() == 3){
            adj[i].push_back(a.first);
        }
        else{
            adj[i].push_back(a.second);
        }
    }
    for(int i = 0 ;i < n; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for(auto& i : topo) cout << i+1 << ' ';
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
