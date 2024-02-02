/*
Problem Name : B. Yet Another Array Partitioning Task 
Author: Abdalrahman Shaban
Date: 31/01/2024 00:13:01
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
    int n, m, k; cin >> n >> m >> k;
    ll arr[n];
    vector<pi> v(n);
    ll sm = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v[i].first = arr[i];
        v[i].second = i;
    }
    sort(allr(v));
    map<ll, int> mp;
    for(int i = 0; i < m*k; i++){
        sm += v[i].first;
        mp[v[i].first]++;
    }
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(mp[arr[i]]){
            mp[arr[i]]--;
            cnt++;
        }
        if(cnt == m){
            cnt = 0;
            ans.push_back(i+1);
        }
    }
    ans.pop_back();
    cout << sm << endl;
    for(auto& i : ans) cout << i << ' ';

}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
