/*
Problem Name : R. Histogram 
Author: Abdalrahman Shaban
Date: 17/01/2024 16:15:24
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

void calc_left_smaller(ll* left_smaller, ll* arr, int n){
    stack<ll> stk;
    for(int i =0 ;i < n; i++){
        while(!stk.empty() && arr[stk.top()] >= arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            left_smaller[i] = -1;
        }
        else{
            left_smaller[i] = stk.top();
        }
        stk.push(i);
    }
}

void calc_right_smaller(ll* right_smaller, ll* arr, int n){
    stack<ll> stk;
    for(int i =n-1 ;i >= 0; i--){
        while(!stk.empty() && arr[stk.top()] >= arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            right_smaller[i] = n;
        }
        else{
            right_smaller[i] = stk.top();
        }
        stk.push(i);
    }
}

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll left_smaller[n], right_smaller[n];
        calc_left_smaller(left_smaller, arr, n);
        calc_right_smaller(right_smaller, arr, n);

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll l = left_smaller[i];
            ll r = right_smaller[i];
            ans = max(ans, (r-l-1)*arr[i]);
        }
        cout << ans << '\n';
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
