/*
Problem Name : Increasing Subsequence 
Author: Abdalrahman Shaban
Date: 09/02/2024 23:23:44
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

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n+1, INF);
    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[l-1] < a[i] && a[i] < dp[l])
            dp[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF)
            ans = l;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
   // int dp[n];
   // memset(dp, 0, sizeof(dp));
   // int mx = 1;
   // for(int i = 0; i < n; i++){
   //     dp[i] = 1;
   //     for(int j = 0; j < i; j++){
   //         if(arr[j] < arr[i]){
   //             dp[i] = max(dp[i], dp[j]+1);
   //             mx = max(mx, dp[i]);
   //         }
   //     }
   // }
    cout << lis(arr);
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
