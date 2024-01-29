/*
Problem Name : B. Binary Palindromes 
Author: Abdalrahman Shaban
Date: 29/01/2024 23:19:23
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef vector<pair<ll, ll>> pi;

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
        int os = 0, zs = 0, ods = 0;
        for(int i = 0; i < n ;i++){
            string s;
            cin >> s;
            if(s.size()&1) ods++;
            for(auto& j : s){
                if(j-'0') os++;
                else zs++;
            }
        }
        int chk = (zs&1) + (os&1);
        if(chk > ods) cout << n-1 << endl;
        else cout << n << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}

