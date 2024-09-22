/*
Problem Name : E. Vlad and an Odd Ordering 
Author: Abdalrahman Shaban
Date: 20/02/2024 21:18:42
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

vector<ll> pre;

void solve(){
    ll n, k; cin >> n >> k; 
    ll tmp = n;
    ll p = 0;
    while(tmp){
        ll sz = (tmp+1)/2;
        ll fst = (1<<p);
        ll df = (1<<(p+1));
        if(k > sz){
            k -= sz;
        }
        else{ // non = fst + (it-1) * df
            ll chk = (n - fst)/df + 1;
            if(chk < k){
                k -= chk;;
            }
            else{
                ll non = fst + (k-1) * df;
                cout << non << endl; return;
            }
        }
        p++;
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
