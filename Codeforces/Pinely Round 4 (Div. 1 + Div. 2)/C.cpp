/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 30/07/2024 02:24:26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(),s.end()

void file(); 
void Fast();

void solve(){
    int n; cin >> n;
    ll arr[n];
    int ev = 0, od = 0;
    for(int i = 0 ;i < n; i++){
        cin >> arr[i];
        if(arr[i]&1) od++;
        else ev++;
    }
    if(od && ev){
        cout << -1 << '\n'; return;
    }
    vector<ll> ans;
    for(ll i = 29; i >= 0; i--){
        ans.push_back((1LL<<i));
    }
    if(ev){
        ans.push_back(1);
    }
    cout << ans.size() << '\n';
    for(auto&i : ans){
        cout << i << ' ';
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
