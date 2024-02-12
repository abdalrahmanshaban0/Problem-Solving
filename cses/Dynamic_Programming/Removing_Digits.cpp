/*
Problem Name : Removing Digits 
Author: Abdalrahman Shaban
Date: 09/02/2024 16:00:52
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


const int N = 1e6+1;
int dp[N];

int rec(int num){
    if(num < 0){
        return 1e9;
    }
    if(num == 0){
        return 0;
    }
    int& ret = dp[num];
    if(~ret) return ret;
    ret = 1e9;
    string s = to_string(num);
    for(auto& c : s){
        int dg = (int)(c - '0');
        ret = min(ret, 1 + rec(num-dg));
    }
    return ret;
}


void solve(){
    int num; cin >> num;
    memset(dp, -1, sizeof(dp));
    cout << rec(num);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
