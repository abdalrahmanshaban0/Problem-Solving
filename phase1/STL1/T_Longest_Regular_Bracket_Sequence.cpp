/*
Problem Name : T. Longest Regular Bracket Sequence 
Author: Abdalrahman Shaban
Date: 18/01/2024 15:49:30
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define clr(arr, x) (memset(arr, x, sizeof arr))
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<ll>
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

bool go(stack<int>& stk, int idx, string& s){
    if(s[idx] == ')' && s[stk.top()] == '('){
        return 1;
    }
    if(s[idx] == '}' && s[stk.top()] == '{'){
        return 1;
    }
    if(s[idx] == ']' && s[stk.top()] == '['){
        return 1;
    }
    if(s[idx] == '>' && s[stk.top()] == '<'){
        return 1;
    }
    return 0;
}

void clear(stack<int>& stk){
    while(!stk.empty()){
        stk.pop();
    }
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    int mx = 0, frqmx = 0;
    vector<int> v(1e6+50, 0);
    stack<int> stk;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c != ')' && c != '}' && c != ']' && c != '>'){
            stk.push(i);
        }
        else{
            if(!stk.empty() && go(stk, i, s)){
                v[i] = 1;
                v[stk.top()] = 1;
                stk.pop();
            }
            else{
                clear(stk);
            }
        }
    }
    int streak = 0;
    for(int i = 0 ; i < n; i++){
        streak += v[i];
        if(!v[i]) streak = 0;
        if(streak > mx){
            mx = streak;
            frqmx = 1;
        }
        else if(streak == mx){
            frqmx++;
        }
    }
    cout << mx << ' ' << (!mx ? 1 : frqmx);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
