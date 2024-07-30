/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 30/07/2024 00:22:40
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(),s.end()

void file(); 
void Fast();

void solve(){
    int n; cin >> n;
    int a[n-1], b[n];
    for(int i = 0 ;i < n-1; i++){
        cin >> a[i];
        b[i] = 0;
    }
    b[0] = a[0];
    
    for(int i = 1; i < n-1; i++){
        b[i] = (a[i]|a[i-1]);
    }
    b[n-1] = a[n-2];
    for(int i = 0; i < n-1; i++){
        if(a[i] != (b[i]&b[i+1])){
            cout << -1 << '\n'; return;
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << ' ';
    }
    cout << '\n';
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
