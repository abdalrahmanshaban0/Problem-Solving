/*
Problem Name : A 
Author: Abdalrahman Shaban
Date: 28/07/2024 01:37:02
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

void file(); 
void Fast();

void solve(){
    int n, m; cin >> n >> m;
    int a[n][m], sm = n*m;
    for(int i = 0; i < n; i++){
        for(int j=  0; j < m; j++){
            cin >> a[i][j];
        }
    }
    if(n == 1 && m == 1){
        cout << -1 << endl; return;
    }
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[(i+1)%n][(j+1)%m] << ' ';
        }
        cout << endl;
    }
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
