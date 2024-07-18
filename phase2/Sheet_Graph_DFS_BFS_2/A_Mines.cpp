/*
Problem Name : A 
Author: Abdalrahman Shaban
Date: 18/07/2024 01:27:26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

struct p{
    ll x,y;
    double s;
    p():x(0),y(0),s(0.0) {}
};

vector<p> pts;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> xpo;

void dfs(int nd, bool f = 1){
    vis[nd] = 1;
    for(auto& ch : adj[nd]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
    if(f)
        xpo.push_back(nd);
}

void solve(){
    ll n; cin >> n;
    pts.resize(n);
    vis.resize(n);
    adj.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y >> pts[i].s;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) if(i!=j){
            if(abs(pts[j].x-pts[i].x) <= pts[i].s/2 &&
               abs(pts[j].y-pts[i].y) <= pts[i].s/2){
                adj[i].push_back(j);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(xpo.begin(),xpo.end());
    vis.clear(), vis.resize(n);
    for(int i = 0; i < n; i++){
        if(!vis[xpo[i]]){
            dfs(xpo[i],0);
            ans++;
        }
    }
    cout << ans << endl;

    pts.clear();
    vis.clear();
    adj.clear();
    xpo.clear();
}

int main() {
    Fast();
    file();
    int t; cin >> t;
    while(t--)
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
