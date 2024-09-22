/*
Problem Name : C. Choose the Different Ones! 
Author: Abdalrahman Shaban
Date: 06/02/2024 17:14:27
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
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m];
        vector<bool> va(k+1, 0), vb(k+1, 0);
        for(int i = 0 ;i < n ;i++){
            cin >> a[i];
            if(a[i] <= k){
                va[a[i]] = 1;
            }
        }
        for(int i = 0; i <  m; i++){
            cin >> b[i];
            if(b[i] <= k){
                vb[b[i]] = 1;
            }
        }
        int temp = 0;
        int cnta = 0, cntb = 0;
        for(int i = 1; i <= k; i++){
            temp += (va[i]|vb[i]);
            if(va[i]) cnta++;
            if(vb[i]) cntb++;
        }
//        cout << cnta << ' ' << cntb << ' ' << temp << endl; continue;
        if(temp != k || cnta < k/2 || cntb < k/2){
            NO;
        }
        else{
            YES;
        }
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
