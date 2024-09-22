/*
Problem Name : E. Klever Permutation 
Author: Abdalrahman Shaban
Date: 06/02/2024 18:01:02
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
        int n, k; cin >> n >> k;
        set<int> st;
        for(int i = 1; i <= n; i++){
            st.insert(i);
        }
        vector<int> perm(n+1);
        int f = 1;
        int shft = 0;
        while(!st.empty()){
            int it = (f ? *st.begin() : *st.rbegin());
            for(int i = 1+shft; i <= n; i+= k){
                perm[i] = it;
                st.erase(it);
                it = it + (f ? 1 : -1);
            }
            f^=1;
            shft++;
        }
        for(int i = 1; i <= n; i++){
            cout << perm[i] << ' ';
        } cout << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
