/*
Problem Name : C. XOR-distance 
Author: Abdalrahman Shaban
Date: 30/01/2024 20:20:37
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


ll a, b, r;
ll go(ll f){
    ll df = abs(a-b);
    ll temp = r;
    ll x = a, y = b;
    for(ll i = 62; i >= 0; i--){
        ll tmp1 = x, tmp2 = y;
        tmp1 = (tmp1 ^ (1LL<<i));
        tmp2 = (tmp2 ^ (1LL<<i));
        if((1LL<<i) <= temp && abs(x-y) > abs(tmp1-tmp2)){
            if(f){f = 0; continue;}
            x = tmp1;
            y = tmp2;
            temp -= (1LL<<i);
        }
    }
    return abs(x-y);
}

void solve(){
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> r;
        cout << min(go(0), go(1)) << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
