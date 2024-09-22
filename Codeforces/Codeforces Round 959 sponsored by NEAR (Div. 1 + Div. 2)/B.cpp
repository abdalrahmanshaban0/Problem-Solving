/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 28/07/2024 02:16:07
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int frq[2] = {0};
    bool ok = 1;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(b[i] == '1'){
                if(!frq[1]){
                    ok = 0; break;
                }
            }
        }
        frq[a[i]-'0']++;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
