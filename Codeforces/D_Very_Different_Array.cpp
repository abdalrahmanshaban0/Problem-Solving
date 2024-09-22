/*
Problem Name : D. Very Different Array 
Author: Abdalrahman Shaban
Date: 04/02/2024 13:17:02
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
        int n, m; 
        cin >> n >> m;
        deque<ll> a(n), b(m);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        sort(all(a));
        sort(all(b));
        ll ans = 0;
        while(!a.empty()){
            ll df1 = abs(a.back()-b.front());
            ll df2 = abs(a.front()-b.back());
            if(df1 > df2){
                ans += df1;
                a.pop_back();
                b.pop_front();
            }
            else{
                ans += df2;
                a.pop_front();
                b.pop_back();
            }
        }
        cout << ans << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
