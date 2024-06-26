/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 09/04/2024 12:02:57
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

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
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    ll n, k; cin >> n >> k;
    ll arr[n];
    for(int i = 0 ;i < n; i++){
        cin >> arr[i];
    }
    ll f = k/2 + k%2, l = k/2;
    for(int i = 0; i< n; i++){
        if(f >= arr[i]){
            f -= arr[i];
            arr[i] = 0;
        }
        else{
            arr[i] -= f;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(l >= arr[i]){
            l -= arr[i];
            arr[i] = 0;
        }
        else{
            arr[i] -= l;
            break;
        }
    }
    int ans = 0;
    for(int i = 0 ;i < n; i++){
        ans += (arr[i] == 0);
    }
    cout << ans << endl;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
