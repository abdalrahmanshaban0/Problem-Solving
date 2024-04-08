/*
Problem Name : D - Diversity of Scores 
Author: Abdalrahman Shaban
Date: 02/03/2024 14:18:28
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
    int n, m; cin >> n >> m;
    set<ll> st;
    vector<ll> v(n+1, 0);
    map<ll, ll> mp;

    mp[0] = n;
    st.insert(0);

    for(int i = 0 ; i < m; i++){
        int p; cin >> p;
        ll val; cin >> val;

        if(mp[v[p]] == 1)
            st.erase(v[p]);

        mp[v[p]]--;

        v[p] += val;

        mp[v[p]]++;
        st.insert(v[p]);

        cout << st.size() << endl;
    }
}

int main() {
    Fast();
    file();
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
