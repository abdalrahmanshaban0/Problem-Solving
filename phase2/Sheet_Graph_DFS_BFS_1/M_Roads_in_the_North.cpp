/*
Problem Name : M - Roads in the North 
Author: Abdalrahman Shaban
Date: 28/04/2024 19:03:43
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

vector<vector<pair<int,ll>>> adj(10001);

void dfs(int nd, int p, int len, int& sr, int& mx){
    if(len > mx){
        mx = len;
        sr = nd;
    }
    for(auto& child : adj[nd]){
        if(child.first != p){
            dfs(child.first, nd, len+child.second, sr, mx);
        }
    }
}

void go(int lst){
    int nd1 = 0; int mx = 0;
    dfs(lst, -1, 0, nd1, mx);
    mx = 0;
    dfs(nd1, -1, 0, nd1, mx);
    cout << mx << endl;
    adj.clear(); adj.resize(10001);
}

void solve(){
    stringstream ss;
    string s;
    int lst;
    while(getline(cin, s)){
        if(!s.empty()){
            ss.clear(); ss << s;
            int a, b, c; ss >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            lst = a;
        }
        else{
            go(lst);
        }
    }
    go(lst);

}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
