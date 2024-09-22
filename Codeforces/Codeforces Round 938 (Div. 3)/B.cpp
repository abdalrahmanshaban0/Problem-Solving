/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 09/04/2024 11:54:49
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

bool solve(){
    int n, c, d; cin >>n >> c >> d;
    int sz = n*n;
    int arr[sz];
    map<int, int> mp;
    int a11 = INT_MAX;
    for(int i = 0; i < sz; i++){
        cin >> arr[i];
        a11 = min(arr[i], a11);
        mp[arr[i]]++;
    }

    for(int i = a11; i < a11+n*c; i+=c){
        if(mp[i]){
            mp[i]--;
            for(int j = i+d; j < i+n*d; j+=d){
                if(mp[j]){
                    mp[j]--;
                }
                else{
                    return 0;
                }
            }
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    while(t--){
        if(solve()) YES;
        else NO;
    }
    return 0;
}
