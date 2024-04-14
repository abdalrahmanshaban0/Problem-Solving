/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 13/04/2024 17:03:41
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

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};

void dorow(vector<vector<int>>& v, int idx){
    for(int i = 0; i < v[idx].size(); i++) v[idx][i] = i+1;
}
void docol(vector<vector<int>>& v, int idx){
    for(int i = 0; i < v.size(); i++) v[i][idx] = v[i][idx] = i+1;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = n-1; i >= 0; i--){
        dorow(v, i);
        docol(v, i);
    }
    int ans = 0;
    for(auto& i : v){
        for(auto& j : i){
            ans += j;
        }
    }
    cout << ans << ' ' << 2*n << endl;
    for(int i = n; i >= 1; i--){
        cout << 1 << ' ' << i;
        for(int j = 1; j <= n; j++){
            cout << ' ' << j;
        }
        cout << endl;
        cout << 2 << ' ' << i;
        for(int j = 1; j <= n; j++){
            cout << ' ' << j;
        }
        cout << endl;
    }
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
