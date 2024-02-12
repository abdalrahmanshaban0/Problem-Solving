/*
Problem Name : A. Farms 
Author: Abdalrahman Shaban
Date: 08/02/2024 18:16:40
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


ll gtmxcoins(ll* arr, int n, ll& moment){
    ll thds = 1LL;
    ll timecost = 0;
    ll coins = 0;
    ll mx = moment * thds;
    for(int i = 0; i < n; i++){
        ll farmcost = max(0LL, arr[i]-coins);
        ll mneeded = farmcost/thds + (farmcost%thds ? 1 : 0); //moments to by farm
        coins += mneeded*thds - arr[i];
        timecost += mneeded;
        if(timecost >= moment) return mx;
        thds++;
        mx = max(mx, (moment-timecost)*thds+coins);
    }
    return mx;
}

void solve(){
    int n; ll m; cin >> n >> m;
    ll arr[n];
    for(int i = 0 ; i< n ;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll ans = m;
    ll l = 0, r = m;
    while(l <= r){
        ll moment = (l+r)/2;
        ll gained = gtmxcoins(arr, n, moment);
        if(gained >= m){
            ans = min(ans, moment);
            r = moment - 1;
        }
        else{
            l = moment + 1;
        }
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
