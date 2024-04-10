/*
Problem Name : E 
Author: Abdalrahman Shaban
Date: 09/04/2024 22:16:10
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

bool chk(string temp, int k){
    int n = temp.size();
    int* prf = new int[n+1] {};
    for(int i  =0; i < n; i++){
        if(i){
            prf[i] += prf[i-1];
        }
        if(prf[i]&1){
            if(temp[i] == '0') temp[i] = '1';
            else temp[i] = '0';
        }
        if(temp[i] == '0'){
            prf[i]++;
            if(i+k > n) return 0;
            prf[i+k]--;
        }
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = n; i >= 1; i--){
        if(chk(s, i)){
            cout << i << endl; return;
        }
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
