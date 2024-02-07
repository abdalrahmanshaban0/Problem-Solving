/*
Problem Name : C. Email Parsing 
Author: Abdalrahman Shaban
Date: 05/02/2024 20:56:27
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
    string s; cin >> s;
    int n = s.size();
    string a, b, c;
    string temp;
    bool ok = 0;
    bool f = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '@'){
            f = 0;
        }
        else if(s[i] == '.'){
            ok = 1;
        }
        if(ok){
            if(s[i] != '.')
                c += s[i];
        }
        if(f){
            a += s[i];
        }
        if(!f && !ok && s[i] != '.' && s[i] != '@'){
            b += s[i];
        }
    }
    if(!a.empty() && !b.empty() && !c.empty() && s == a+"@"+b+"."+c) cout << "YES";
    else cout << "NO";
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
