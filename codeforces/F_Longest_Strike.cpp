/*
Problem Name : F. Longest Strike 
Author: Abdalrahman Shaban
Date: 29/01/2024 18:39:14
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;

#define F first
#define S second
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
        int n, k; cin >> n >> k;
        vi v(n);
        map<ll, int> mp;
        for(auto& i : v){
            cin >> i;
            mp[i]++;
        }

        int m = mp.size();
        pi chk[m];
        int it = 0;
        for(auto& i : mp){
            chk[it].F = i.F;
            chk[it].S = i.S;
            it++;
        }

        ll l = 0, r = 0;
        ll mxl = 0, mxr = 0;
        bool ok = 0;
        for(int i = 0; i < m; i++) if(chk[i].S >= k){
            ok = 1;
            l = chk[i].F;
            int j = i+1;
            ll fst = l;
            for(; j < m; j++){
                if(chk[j].S >= k && fst+1 == chk[j].F){
                    r++;
                    fst++;
                }
                else{
                    break;
                }
            }
            if(r >= mxr){
                mxr = r;
                mxl = l;
            }
            r = 0;
            i = j-1;
        }
        if(!ok){
            cout << -1 << endl;
        }
        else cout << mxl << ' ' << mxl+mxr << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
