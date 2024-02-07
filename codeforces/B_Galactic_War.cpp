/*
Problem Name : B. Galactic War 
Author: Abdalrahman Shaban
Date: 05/02/2024 21:07:50
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

int merge(int* a, int* b, int n, int m){
    int it1 = 0, it2 = 0;
    int ans = 0;
    while(it1 < n && it2 < m){
        bool f = 1;
        if(a[it1] <= b[it2] && it2+1 < m && a[it1] <= b[it2+1]){
            cout << a[it1] << " " << b[it2] << endl;
            if(f){
                ans++;
                f = 0;
            }
            it1++;
        }
        else{
            cout << "here " << a[it1] << " " << b[it2] << endl;
            it2++;
        }
    }
    if(it1 < n){
        ans++;
    }
    return ans;
}

void solve(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        cout << merge(a, b, n, m) << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
