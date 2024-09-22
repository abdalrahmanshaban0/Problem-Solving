/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 05/06/2024 15:18:24
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
void vin(vector<ll>& v) {for(auto& i : v) cin >> i;}

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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n);
        for(auto& i : v) cin >> i;

        vi gg(n-1), gg2(n-2);
        for(int i = 0 ;i < n-1; i++){
            gg[i] = gcd(v[i], v[i+1]);
            if(i < n-2){
                gg2[i] = gcd(v[i], v[i+2]);
            }
        }
        if(is_sorted(gg.begin()+1, gg.end()) || is_sorted(gg.begin(), gg.end()-1)){
            YES; continue;
        }
        vi prf(n-1), suf(n-1);
        ll val = gg[n-2];
        for(int i = n-2; i >= 0; i--){
            if(gg[i] <= val){
                suf[i] = 1;
            }
            else{
                break;
            }
            val = gg[i];
        }
        val = gg[0];
        for(int i = 0; i < n-1; i++){
            if(gg[i] >= val){
                prf[i] = 1;
            }
            else{
                break;
            }
            val = gg[i];
        }
        bool ok = 0;
        for(int i = 1 ;i < n-1; i++){
            ll rp = gg2[i-1];
            if((i+1 >= n-1 || (suf[i+1] && rp<=gg[i+1])) && (i-2 < 0 || (prf[i-2] && rp >= gg[i-2]))){
                ok = 1; break;
            }
        }
        (ok ? YES : NO);
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
