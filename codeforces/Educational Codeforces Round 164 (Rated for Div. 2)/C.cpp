/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 12/04/2024 20:23:51
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
    string x, y; cin >> x >> y;
    for(int i = 0; i < min(x.size(), y.size()); i++){
        if(x[i] != y[i]){
            if(x[i] < y[i]){
                for(int j = i+1; j < min(x.size(), y.size()); j++){
                    if(x[j] < y[j]){
                        swap(x[j], y[j]);
                    }
                }
            }
            else{
                for(int j = i+1; j < min(x.size(), y.size()); j++){
                    if(x[j] > y[j]){
                        swap(x[j], y[j]);
                    }
                }
            }
            break;
        }
    }
    cout << x << endl << y << endl;
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
