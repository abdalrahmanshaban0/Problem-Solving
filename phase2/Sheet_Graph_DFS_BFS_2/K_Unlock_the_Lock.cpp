/*
Problem Name : K - Unlock the Lock 
Author: Abdalrahman Shaban
Date: 18/07/2024 03:09:56
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

void solve(){
    int t = 1;
    while(true){
        int l, u, r; cin >> l >> u >> r;
        if( l == u && u == r && r == 0) break;
        vector<int> rs(r);
        for(auto& i : rs) cin >> i;
        queue<int> q;
        q.push(l);
        int stps = 0, ans = -1;
        vector<bool> vis(1e6);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front(); 
                q.pop();
                vis[cur] = 1;
                if(cur == u){
                    ans = stps;
                    break;
                }
                for(auto& i : rs){
                    int val = (cur+i)%10000;
                    if(!vis[val]){
                        q.push(val);
                        vis[val] = 1;
                    }
                }
            }
            ++stps;
        }
        cout << "Case " << t++ << ": ";
        if(ans == -1){
            cout << "Permanently Locked";
        }
        else{
            cout << ans;
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
