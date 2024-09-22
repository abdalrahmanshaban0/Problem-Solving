/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 03/06/2024 17:38:32
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
void vin(vector<ll>& v) {for(auto& i : v) cin >> i;}

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
        int n, f, k; cin >> n >> f >> k;
        vector<pair<int, int>> v(n);
        map<int, int> mp;
        for(int i = 0 ;i < n; i++){
            cin >> v[i].first;
            mp[v[i].first]++;
            v[i].second = i;            
        }
        int h = v[f-1].first;
        sort(allr(v));
        bool ok = 0;
        f--;
        bool chk = 0, u = 0;
        for(int i = 0 ;i < k; i++){
            if(v[i].second == f){
                ok = 1;
            }
            if(v[i].first == h){
                u = 1;
            }
        }
        for(int i = k; i < n; i++){
            if(v[i].first == h){
                chk = 1; break;
            }
        }
        if(ok && chk){
            cout << "MAYBE\n";
        }
        else{
            if(ok) YES;
            else{
                if(u && chk) {
                    cout << "MAYBE\n";
                }
                else{
                    NO;
                }
            }
        }
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
