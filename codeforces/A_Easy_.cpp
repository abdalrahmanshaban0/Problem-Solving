/*
Problem Name : A. Easy? 
Author: Abdalrahman Shaban
Date: 05/02/2024 21:33:06
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

bool chkpal(string s){
    for(int i =0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]) return 0;
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1;
    deque<char> dq;
    char c = 'z';
    for(int i = 0 ;i < n; i++){
        if(dq.empty()){
            dq.push_back(s[i]);
            c = min(c, s[i]);
        }
        else{
            if(s[i] == dq.front() && s[i] >= c){
                dq.push_back(s[i]);
                c = min(c, s[i]);
            }
            else{
                dq.clear();
                dq.push_back(s[i]);
                c = s[i];
            }
        }
        ans = max(ans, (int)dq.size());
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
