/*
Problem Name : Palindrome Reorder 
Author: Abdalrahman Shaban
Date: 06/02/2024 01:06:23
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
    int frq[26] = {};
    for(auto& i : s){
        frq[i-'A']++;
    }
    int cnt = 0;
    char c; 
    for(char i = 'A'; i <= 'Z'; i++){
        if(frq[i-'A']&1){
            cnt++;
            c = i;
        }
        if(cnt == 2){
            cout << "NO SOLUTION";
            return;
        }
    }
    deque<char> dq;
    if(cnt){
        frq[c-'A']--;
        dq.push_back(c);
    }
    for(char i = 'A'; i <= 'Z'; i++){
        while(frq[i-'A']){
            dq.push_back(i);
            dq.push_front(i);
            frq[i-'A']-=2;
        }
    }
    for(auto& i : dq) cout << i;
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
