/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 10/05/2024 18:57:16
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
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == '0' && s[i-1] == '1'){
                ans++;
            }
        } 
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == '1' && s[i-1] == '0'){
                cnt++;
            }
        }
        cout << ans+1+(cnt > 1 ? cnt-1 : 0) << endl;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
