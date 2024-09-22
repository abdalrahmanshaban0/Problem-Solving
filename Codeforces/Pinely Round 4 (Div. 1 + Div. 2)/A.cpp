/*
Problem Name : A 
Author: Abdalrahman Shaban
Date: 30/07/2024 00:16:41
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(),s.end()

void file(); 
void Fast();

void solve(){
    int n; cin >> n; 
    int arr[n];
    for(int i = 0 ;i < n; i++){
        cin >> arr[i];
    }
    int mx = 0, mxidx = 0;
    for(int i = 0 ;i < n; i++){
        if(i % 2 == 0 && (n-1-i) % 2 == 0 && mx < arr[i]){
            mx = arr[i];
        }
    }
    cout << mx << endl;
}

int main() {
    Fast();
    file();
    int t ;cin >> t;
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
