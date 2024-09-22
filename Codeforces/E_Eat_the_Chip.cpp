/*
Problem Name : E. Eat the Chip 
Author: Abdalrahman Shaban
Date: 04/02/2024 14:26:24
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

int dxa[] = {1, 1, 1};
int dya[] = {0, -1, 1};
int dxb[] = {-1, -1, -1};
int dyb[] = {0, -1, 1};


void solve(){
    int t; cin >> t;
    while(t--){
        ll h, w;
        cin >> h >> w;
        ll xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        ll dsx = abs(xa-xb);
        if(xb < xa){
            cout << "Draw\n";
            continue;
        }

        if(dsx&1){ // Alice            
            ll r1 = min(w, ya+(dsx+1)/2);
            ll r2 = min(w, yb+dsx/2);
            ll l1 = max(ya-(dsx+1)/2, 1LL);
            ll l2 = max(yb-dsx/2, 1LL);
            if(l1 <= l2 && r1 >= r2){
                cout << "Alice\n";
            }
            else{
                cout << "Draw\n";
            }
        }
        else{
            ll r1 = min(w, ya+dsx/2);
            ll r2 = min(w, yb+dsx/2);
            ll l1 = max(ya-dsx/2, 1LL);
            ll l2 = max(yb-dsx/2, 1LL);
            if(l1 >= l2 && r1 <= r2){
                cout << "Bob\n";
            }
            else{
                cout << "Draw\n";
            }
        }
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
