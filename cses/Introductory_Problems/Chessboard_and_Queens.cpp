/*
Problem Name : Chessboard and Queens 
Author: Abdalrahman Shaban
Date: 06/02/2024 23:44:08
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

vector<string> v(8);
bool col[8], dia1[16], dia2[16];
int ans;
void rec(int y){
    if(y == 8){
        ans++;
        return;
    }
    for(int x = 0; x < 8; x++){
        if(col[x] || dia1[x+y] || dia2[x-y+8-1] || v[x][y] == '*') continue;
        col[x] = dia1[x+y] = dia2[x-y+8-1] = 1;
        rec(y+1);
        col[x] = dia1[x+y] = dia2[x-y+8-1] = 0;
    }
}

void solve(){
    for(auto& i : v) cin >> i;
    rec(0);
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
