/*
Problem Name : C. Can I Square? 
Author: Abdalrahman Shaban
Date: 26/01/2024 22:21:23
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define clr(arr, x) (memset(arr, x, sizeof arr))
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<ll>
const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool issq(ll n){
    ll temp = sqrt(n);
    return (temp*temp == n);
}

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n];
        ll sm = 0;
        for(int i = 0 ;i < n; i++){
            cin >> arr[i];
            sm += arr[i];
        }
        if(issq(sm)) YES;
        else NO;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
