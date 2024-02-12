/*
Problem Name : Edit Distance 
Author: Abdalrahman Shaban
Date: 09/02/2024 21:43:49
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
string a, b;
ll dp[5000][5000];
ll rec(int i, int j){
    if(i == 0 && j == 0){
        if(a[i] == b[j])
            return 0;
        else
            return 1;
    }
    if(i < 0){
        return j+1;
    }
    if(j < 0){
        return i+1;
    }
    ll& ret = dp[i][j];
    if(~ret) return ret;
    ret = INT_MAX;

    if(a[i] != b[j]){
        ret = min({rec(i-1, j)+1, rec(i, j-1)+1, rec(i-1, j-1)+1});
    }
    else{
        ret = min(ret, rec(i-1, j-1));
    }
    return ret;
}
void solve(){
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << rec(a.size()-1, b.size()-1);
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
