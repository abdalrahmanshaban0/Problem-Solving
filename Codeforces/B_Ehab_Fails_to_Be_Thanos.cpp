/*
Problem Name : B. Ehab Fails to Be Thanos 
Author: Abdalrahman Shaban
Date: 03/02/2024 22:32:26
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
    ll n; cin >> n;
    ll arr[2*n];
    ll sm1 = 0, sm2 = 0;
    for(int i = 0; i < 2*n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+2*n);
    for(int i = 0; i < n*2; i++){
        if(i < n)
            sm1+=arr[i];
        else sm2+=arr[i];
    }
    if(sm1 == sm2){
        cout << -1;
    }
    else{
        for(int i = 0; i < 2*n ;i++){
            cout << arr[i] << ' ';
        }
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
