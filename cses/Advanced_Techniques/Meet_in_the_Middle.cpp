/*
Problem Name : Meet in the Middle 
Author: Abdalrahman Shaban
Date: 06/02/2024 14:55:56
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
    int n; ll x;
    cin >> n >> x;
    ll arr[n];
    vi a(n/2), b((n+1)/2);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i < n/2){
            a[i] = arr[i];
        }
        if(i >= n/2){
            b[i-n/2] = arr[i];
        }
    }
    vector<ll> sa, sb;
    int na = n/2, nb = (n+1)/2;
    for(int i = 0 ;i < (1<<na); i++){
        ll sm1 = 0;
        for(int j = 0; j < na; j++){
            if(i&(1<<j)){
                sm1 += a[j];
                if(sm1 > x) break;
            }
        }
        if(sm1 <= x){
            sa.push_back(sm1);
        }
    }
    ll ans = 0;
    for(int i = 0; i < (1<<nb); i++){
        ll sm2 = 0;
        for(int j = 0; j < nb; j++){
            if(i&(1<<j)){
                sm2 += b[j];
                if(sm2 > x) break;
            }
        }
        if(sm2 <= x){
            sb.push_back(sm2);
        }
    }
    sort(all(sb));
    for(auto& i : sa){
        ans += (upper_bound(all(sb), x-i) - lower_bound(all(sb), x-i));
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
