/*
Problem Name : I - Prime Path 
Author: Abdalrahman Shaban
Date: 17/07/2024 12:18:49
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

bool ispr(int num){
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

void solve(){
    int l, r; cin >> l >> r;
    queue<int> q;
    q.push(l);
    vector<bool> vis(1e5);
    int dst = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            bool ok = 0;
            int cur = q.front();
            q.pop();
            if(cur == r){
                cout << dst << endl; return;
            }
            vis[cur] = 1;
            string s = to_string(cur);
            for(int i = 0; i < s.size(); i++){
                char temp = s[i];
                for(char j = (i==0?'1':'0'); j <= '9'; j++){
                    s[i] = j;
                    int val = stoi(s);
                    if(!vis[val] && ispr(val)){
                        q.push(val);
                        vis[val] = 1;
                    }
                }
                s[i] = temp;
            }
        }
        dst++;
    }
    cout << "Impossible" << endl;
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
