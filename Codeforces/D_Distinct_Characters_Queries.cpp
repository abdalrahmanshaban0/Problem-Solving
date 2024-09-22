/*
Problem Name : D. Distinct Characters Queries 
Author: Abdalrahman Shaban
Date: 29/02/2024 15:49:54
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
    string s; cin >> s;
    int n = s.size();
    vector<set<int>> v(26);
    for(int i = 0; i < n ;i++){
        v[s[i]-'a'].insert(i+1);
    }
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 2){
            int l, r; cin >> l >> r;
            int cnt = 0;
            for(auto& i : v){
                auto it = i.lower_bound(l);
                if(it != i.end()){
                    if(*it >= l && *it <= r){
                        cnt++;
                    }
                }
            }
            cout << cnt << endl;
        }
        else{
            int idx; char ch; cin >> idx >> ch;
            v[s[idx-1]-'a'].erase(idx);
            v[ch-'a'].insert(idx);
            s[idx-1] = ch;
        }
    }
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
