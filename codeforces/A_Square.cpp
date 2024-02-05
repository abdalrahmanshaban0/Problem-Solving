/*
Problem Name : A. Square 
Author: Abdalrahman Shaban
Date: 04/02/2024 12:37:03
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

void solve(){
    int t; cin >> t;
    while(t--){
        vector<pair<int, int>> v(4);
        for(int i = 0 ;i < 4; i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(all(v));
        int s=  0;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j< 4; j++){
                if(v[i].first == v[j].first){
                    s =abs( v[i].second-v[j].second);
                    break;
                }
                if(v[i].second == v[j].second){
                    s = abs(v[i].first-v[j].first);
                    break;
                }
            }
            if(s) break;
        }
        cout << s * s << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
