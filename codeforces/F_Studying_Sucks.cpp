/*
Problem Name : F. Studying Sucks 
Author: Abdalrahman Shaban
Date: 04/02/2024 00:05:26
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
    int n; cin >> n;
    ll arr[n], arr2[n];
    vector<ll> v(n), vv(n);
    map<ll, int> mp, mpp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr2[i] = arr[i];
        v[i] = arr[i];
        vv[i] = v[i];
        mp[v[i]] = i;
        mpp[v[i]] = i;
    }
    sort(all(v));
    sort(allr(vv));
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != v[i]){
            a++;
            mp[arr[i]] = mp[v[i]];
            swap(arr[i], arr[mp[v[i]]]);
            mp[v[i]] = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(arr2[i] != vv[i]){
            b++;
            mpp[arr2[i]] = mpp[vv[i]];
            swap(arr2[i], arr2[mpp[vv[i]]]);
            mpp[vv[i]] = i;
        }
    }
    cout << min(a, b);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
