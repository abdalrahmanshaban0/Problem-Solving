/*
Problem Name : E 
Author: Abdalrahman Shaban
Date: 10/05/2024 19:23:19
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

void solve(){
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vi a(k), b(k);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        while (q--) {
            ll d;
            cin >> d;
            int idx = lower_bound(a.begin(), a.end(), d)-a.begin();
            if (idx == 0)
                cout << d * b[0] / a[0] << " ";
            else
                cout << (b[idx - 1] + ((d - a[idx - 1]) * (b[idx] - b[idx - 1])) / (a[idx] - a[idx - 1])) << " ";
        }
        cout << endl;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
