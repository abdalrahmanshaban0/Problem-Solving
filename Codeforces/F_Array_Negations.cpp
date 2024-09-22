/*
Problem Name : F. Array Negations 
Author: Abdalrahman Shaban
Date: 08/02/2024 18:04:43
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

void solve(){
    int t; cin >> t;
    while(t--){
        int n , k; cin >> n >> k;
        int arr[n];
        for(int i = 0 ;i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int cnt = k;
        for(int i = 0; i < min(n, k) && arr[i] < 0; i++){
            arr[i] = -arr[i];
            cnt--;
        }
        int sm = 0;
        sort(arr, arr+n);
        if(cnt&1) arr[0] = -arr[0];
        for(int i = 0 ;i < n; i++){
            sm += arr[i];
        }
        cout << sm << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
