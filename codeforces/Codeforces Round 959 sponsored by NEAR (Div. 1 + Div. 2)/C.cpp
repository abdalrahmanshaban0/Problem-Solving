/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 28/07/2024 02:42:03
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define all(s) s.begin(),s.end()

void file(); 
void Fast();

void solve(){
    ll n, k; cin >> n >> k;
    ll arr[n];
    vector<ll> prf(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        prf[i] = arr[i];
    }
    for(int i = 1; i < n; i++) prf[i] += prf[i-1];
    ll ans = n*(n+1)/2;
    ll dp[n+1]; memset(dp,0,sizeof(dp));
    for(int i = n-1; i >= 0; i--){
        int idx = -1, l = i, r = n-1;
        while(l<=r){
            int md = r - (r-l)/2;
            if(prf[md]-(i ? prf[i-1] : 0) > k){
                idx = md;
                r = md-1;
            }
            else{
                l = md+1;
            }
        }
        if(~idx){
            dp[i]  = 1+dp[idx+1];
            ans -= dp[i];
        }
    }
    cout << ans << endl;

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
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
}
