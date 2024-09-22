/*
Problem Name : A 
Author: Abdalrahman Shaban
Date: 03/06/2024 17:35:00
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
        int n ,m ; cin >> n >> m;
        vector<int> v(7);
        string s; cin >> s;
        for(auto& i : s){
            v[(i-'A')]++;
        }
        int ans = 0;
        for(int i = 0; i < 7; i++){
            if(v[i] < m){
                ans += m-v[i];
            }
        }
        cout << ans << endl;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
