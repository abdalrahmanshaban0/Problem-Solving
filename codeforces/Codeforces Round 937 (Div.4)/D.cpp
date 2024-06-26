/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 28/03/2024 17:36:47
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

const int N = 1e5+1;
vector<ll> v;

bool isbr(ll num){
    while(num){
        if(num % 10 > 1) return 0;
        num /= 10;
    }
    return 1;
}

void solve(){
    ll n; cin >> n;
    for(auto& i : v){
        while(n % i == 0){
            n /= i;
        }
    }
    if(isbr(n)) YES;
    else NO;
}

int main() {
    Fast();
    file();

    for(int i = 2; i <= N; i++){
        if(isbr(i)) v.push_back(i);
    }
    reverse(all(v));

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
