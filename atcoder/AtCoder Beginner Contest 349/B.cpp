/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 13/04/2024 14:04:52
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
    string s; cin >> s; 
    map<char, int> mp;
    for(auto& i : s) mp[i]++;
    int chk  =0;
    for(int i = 1; i <= s.size(); i++){
        int cnt = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp[c] == i){
                cnt++;
            }
        }
        if(cnt == 2 || cnt == 0){
            chk++;
        }
    }
    if(chk == s.size()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
