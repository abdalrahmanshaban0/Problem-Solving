/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 06/04/2024 13:16:50
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
    ll a, b, c; cin >> a >> b >> c;
    int sz = log2(c)+1;
    int cs = 0;
    for(int i = 0; i < sz; i++){
        if(c&(1LL<<i)) cs++;
    }
    ll x = 0, y = 0;
    for(ll i = 0; i < sz; i++){
        if(a+b > cs){
            if((c&(1LL<<i)) == 0){
                x |= (1LL<<i);
                y |= (1LL<<i);
                a--; b--;
            }
        }
    }
    for(ll i = 0; i < sz; i++){
        if((c&(1LL<<i))){
            if(a > b){
                x |= (1LL<<i);
                a--;
            }
            else{
                y |= (1LL<<i);
                b--;
            }
        }
    }
    if(a!=b){
        cout << -1; return;
    }
    ll szx = log2(x)+1, szy = log2(y)+1;
    ll pp = max(szx, szy);
    
    while(a && b){
        x |= (1LL<<pp);
        y |= (1LL<<pp);
        if(x < 0 || y < 0){
            cout << -1; return;
        }
        pp++;
        a--; b--;
    }
    cout << x << " " << y;
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
