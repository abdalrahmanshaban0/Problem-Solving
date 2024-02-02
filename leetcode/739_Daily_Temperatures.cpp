/*
Problem Name : 739. Daily Temperatures 
Author: Abdalrahman Shaban
Date: 31/01/2024 22:00:46
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
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        stack<int> stk;
        vector<int> ds(n, 0);
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && v[stk.top()] <= v[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ds[i] = stk.top()-i;
            }
            stk.push(i);
        }
        return ds;
    }
};

void solve(){
    
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
