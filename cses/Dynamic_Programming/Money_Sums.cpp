/*
Problem Name : Money Sums 
Author: Abdalrahman Shaban
Date: 09/02/2024 22:10:26
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

int n;
set<int> ans;

int dp[100][100000];
int rec(int idx, int sm, int* arr){
    if (idx == n){
        if(sm)
            ans.insert(sm);
        return sm;
    }
    int& ret = dp[idx][sm];
    if(~ret){
        return ret;
    }
    ret = rec(idx+1, sm, arr);
    ret = rec(idx+1, sm + arr[idx], arr);
    return ret;
}
void solve(){
     cin >> n; 
    int arr[n];
    for(int i = 0 ;i< n; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    rec(0, 0, arr);
    cout << ans.size() << endl;
    for(auto& i  : ans) if(i) cout << i << ' ';
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
