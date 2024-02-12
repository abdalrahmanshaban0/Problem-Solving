/*
Problem Name : 368. Largest Divisible Subset 
Author: Abdalrahman Shaban
Date: 09/02/2024 13:54:42
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


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        int dp[n+1];
        memset(dp, 1, sizeof(dp));
        int mx = 1;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(v[i] % v[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                    mx = max(mx, dp[i]);
                }
            }
        }
        int temp = -1;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--){
            if(dp[i] == mx && (temp == -1 || (temp % v[i] == 0))){
                ans.push_back(v[i]);
                temp = v[i];
                mx--;
            }
        }
        return ans;
    }
};

void solve(){
    Solution obj;
    vector<int> v = {1};
    vector<int> ret = obj.largestDivisibleSubset(v);
    for(auto& i : ret) cout << i << ' ';
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
