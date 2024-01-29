/*
Problem Name : E. Romantic Glasses 
Author: Abdalrahman Shaban
Date: 26/01/2024 23:03:04
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

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n], prf[n];
        for(int i = 0 ;i < n; i++){
            cin >> arr[i];
            if(i&1)
                prf[i] = arr[i];
            else
                prf[i] = -arr[i];
        }
        map<ll, int> mp;
        mp[prf[0]] = 0;
        bool ok = 0;
        for(int i = 1; i < n ;i++){
            prf[i] += prf[i-1];
            if(mp.count(prf[i]) || prf[i] == 0){
                ok = 1;
                break;
            }
            mp[prf[i]] = i;
        }
        if(ok) YES;
        else NO;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
