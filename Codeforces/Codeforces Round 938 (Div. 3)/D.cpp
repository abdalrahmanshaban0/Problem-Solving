/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 09/04/2024 13:47:14
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
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> mp;
    for(int i = 0; i < m; i++){
        cin >> b[i]; mp[b[i]]++;
    }
    int l = 0, r = 0, cnt = 0, ans = 0;
    map<int, int> mpp;
    while(r < m){
        if(mpp[a[r]] < mp[a[r]]) cnt++;
        mpp[a[r++]]++;
    }
    if(cnt >= k) ans++;
    for(; r < n; r++){
        if(mpp[a[r]] < mp[a[r]]) cnt++;
        mpp[a[r]]++;
        mpp[a[l]]--;
        if(mpp[a[l]] < mp[a[l]]){
            cnt--;
        }
        l++;
        if(cnt >= k) ans++;
    }
    cout << ans << endl;
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
