/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 30/04/2024 18:11:06
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
    cin.tie(NULL);
    cout.tie(NULL);
}

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};

void solve(){
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vi v(n); for(auto& i : v) cin >> i;
        vi vv(v);
        sort(all(vv));
        ll val =  0, sm = 0;
        ll sn = LONG_LONG_MAX;
        for(int i = 0 ;i < n; i++){
            sm += vv[i];
            ll hh = (sm+k)/(i+1);
            sn = min(sn, hh);
        }
        for(auto& i : v){
            if(i < sn){
                if(k >= sn-i){
                    k -= (sn-i);
                    i = sn;
                }
                else{
                    i += k;
                    k = 0;
                    break;
                }
            }
        }
        ll ans = sn * n;
        ans -= (n-1);
        for(int i = 0; i < n; i++){
            if(v[i] > sn){
                ans++;
            }
            else if(v[i] == sn && k){
                ans++; k--;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
