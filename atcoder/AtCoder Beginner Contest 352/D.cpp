/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 04/05/2024 15:57:09
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
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    for(int i = 0 ;i < n ;i++){
        cin >> v[i].first; v[i].second = i;
    }
    sort(all(v));
    set<ll> st;
    for(int i = 0 ;i < k; i++){
        st.insert(v[i].second);
    }
    ll ans = *st.rbegin()-*st.begin();
    ll l = 0, r = k;
    for(; r < n; r++){
        st.erase(v[l++].second);
        st.insert(v[r].second);
        ans = min(ans, *st.rbegin()-*st.begin());
    }
    cout << ans ;
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
