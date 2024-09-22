/*
Problem Name : F. Greetings 
Author: Abdalrahman Shaban
Date: 27/01/2024 00:32:07
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define clr(arr, x) (memset(arr, x, sizeof arr))
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<ll>
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

struct p{
    ll x;
    ll d;
};
bool cmp(p a, p b){
    return(a.x > b.x);
}
void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        p arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].x >> arr[i].d;
        }
        sort(arr, arr+n, cmp);
        ordered_set<ll> st;
        ll ans = 0;
        for(int i = 0 ;i < n; i++){
            int lo = st.order_of_key(arr[i].x);
            int hi = st.order_of_key(arr[i].d);
            st.insert(arr[i].d);
            ans += hi-lo;
            cout << lo << ' ' << hi << '\n';
        }
        cout << max(ans, 0LL) << '\n';
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
