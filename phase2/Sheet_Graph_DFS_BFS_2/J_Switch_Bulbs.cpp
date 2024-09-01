/*
Problem Name : J - Switch Bulbs 
Author: Abdalrahman Shaban
Date: 22/07/2024 01:14:26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int blb; cin >> blb;
            adj[i].push_back(blb);
        }
    }
    map<string,bool> vis;
    map<string,int> mpstp;

    queue<string> q;
    string in(n,'0');
    q.push(in); 
    int stps = 0;
    while(!q.empty()){
        int sz = q.size();
        bool ok = 0;
        while(sz--){
            string cur = q.front();                
            q.pop();
            vis[cur] = 1;
            mpstp[cur] = stps;
            for(int l = 0; l < m; l++){
                string temp = cur;
                for(int j = 0; j < adj[l].size(); j++){
                    temp[n-1-adj[l][j]] = (temp[n-1-adj[l][j]] == '1' ? '0' : '1');
                }
                if(!vis[temp]){
                    vis[temp] = 1;
                    q.push(temp);
                }
            }
        }
        ++stps;
    }
    int qu; cin >> qu;
    while(qu--){
        string s; cin >> s;
        if(count(s.begin(), s.end(),'0') == s.size()){
            cout << 0 << endl;
        }
        else cout << (mpstp[s] == 0 ? -1 : mpstp[s]) << endl;
    }
}

int main() {
    Fast();
    file();
    int t; cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ":\n";
        solve();
        cout << endl;
    }

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
