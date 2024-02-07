/*
Problem Name : Grid Paths 
Author: Abdalrahman Shaban
Date: 05/02/2024 13:37:32
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
 
string s;
string temp;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string di = "RLDU";
bool vis[7][7];
bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < 7 && j < 7 && !vis[i][j]);
}
 
bool optup(int i, int j){
    return (!valid(i-1, j) && j+1 < 7 && j && !vis[i][j+1] && !vis[i][j-1]);
}
bool optdown(int i, int j){
    return (!valid(i+1, j) && j+1 < 7 && j && !vis[i][j+1] && !vis[i][j-1]);
}
bool optright(int i, int j){
    return (!valid(i, j+1) && i+1 < 7 && i && !vis[i+1][j] && !vis[i-1][j]);
}
bool optleft(int i, int j){
    return (!valid(i, j-1) && i+1 < 7 && i && !vis[i+1][j] && !vis[i-1][j]);
}
 
ll ans = 0;
void rec(int idx, int i, int j){
    if(!valid(i, j)){
        return;
    }    
    if(i==6&&j==0){
        if(idx == 48) ans++;
        return;
    }
    vis[i][j] = 1;
    if((s[idx] == '?' || s[idx] == 'R')  && valid(i, j+1) && !optright(i, j+1)){
        rec(idx+1, i, j+1);
    }
    if((s[idx] == '?' || s[idx] == 'L') && valid(i, j-1) && !optleft(i, j-1) ){
        rec(idx+1, i, j-1);
    }
    if((s[idx] == '?' || s[idx] == 'U') && valid(i-1, j) && !optup(i-1, j)){
        rec(idx+1, i-1, j);
    }
    if((s[idx] == '?' || s[idx] == 'D') && valid(i+1, j) && !optdown(i+1, j) ){
        rec(idx+1, i+1, j);
    }
    vis[i][j] = 0;
}
 
void solve(){
    memset(vis, 0, sizeof(vis));
    cin >> s;
    rec(0, 0, 0);
    cout << ans;
}
 
int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
