/*
Problem Name : C. Vlad and a Sum of Sum of Digits 
Author: Abdalrahman Shaban
Date: 20/02/2024 14:17:16
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
    cin.tie(nullptr);
    cout.tie(nullptr);
}


ll smdg(ll n){
    ll ret = 0;
    while(n){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
const int N = 3e5;
vector<ll> pre(N);

void solve(){
    ll n; cin >> n;
    cout << pre[n] << endl;
}

int main() {
    Fast();
    file();
    
    for(int i = 1; i < N; i++){
        pre[i] = smdg(i);
    }
    for(int i = 2; i < N ; i++){
        pre[i] += pre[i-1];
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
