/*
Problem Name : D. Find the Different Ones! 
Author: Abdalrahman Shaban
Date: 06/02/2024 17:25:51
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
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<pair<int, int>> v;
        for(int i = 0; i < n-1; i++){
            if(arr[i] != arr[i+1]){
                v.push_back({i+1, i+2});
            }
        } 
//        for(auto& i : v) cout << i.first << ' ' << i.second << endl;
//         return;

        int q; cin >> q;
        while(q--){
            int l, r; cin >> l >> r;
            auto it1 = lower_bound(all(v), make_pair(l, 0));
            if(it1 == v.end()){
                cout << -1 << ' ' << -1 << endl;
                continue;
            }
            int it = it1 - v.begin();
            if(v[it].first < l || v[it].second > r){
                cout << -1 << " " << -1 << endl;
                continue;
            }
            cout << v[it].first << ' ' << v[it].second << endl;
        }
        cout << endl;
    }

}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
