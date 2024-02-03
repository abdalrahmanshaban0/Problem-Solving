/*
Problem Name : 1043. Partition Array for Maximum Sum 
Author: Abdalrahman Shaban
Date: 03/02/2024 11:41:01
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
    int dp[501][501];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int rec(int idx, int& k, vector<int>& arr){
        if(idx >= arr.size()){
            return 0;
        }
        int& ret = dp[idx][k];
        if(~ret) return ret;
        vector<int> v;
        int mx = 0;
        int cnt = 1;
        for(int i = idx; i < min(idx+k, (int)arr.size()); i++){
            mx = max(arr[i], mx);
            ret = max(ret, mx*cnt + rec(i+1, k, arr));
            cnt++;
        }
        return ret;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return rec(0, k, arr);
    }
};

void solve(){
    Solution obj;
    vector<int> v=  {1,15,7,9,2,5,10};
    int k = 3;
    cout << obj.maxSumAfterPartitioning(v, k);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
