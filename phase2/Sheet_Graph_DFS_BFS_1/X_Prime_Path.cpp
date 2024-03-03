/*
Problem Name : X - Prime Path 
Author: Abdalrahman Shaban
Date: 02/03/2024 11:23:59
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

const int M = 1e4;
vector<int> prms(M+1, 1);

void sieve(){
    prms[0] = 0, prms[1] = 0;
    for(int i = 2; i*i <= M; i++){
        if(prms[i]){
            for(int j = i*i; j <= M; j+= i){
                prms[j] = 0;
            }
        }
    }
}

int n;
vector<int> nodes;
vector<vector<int>> adj(1e4);

bool valid(int num1, int num2){
    int cnt = 0;
    while(num1 && num2){
        if(num1 % 10 != num2 % 10) cnt++;
        num1/=10; num2/=10;
        if(cnt >= 2) return 0;
    }
    return 1;
}

void bld(){
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < n; j++) if(i != j){
            if(valid(nodes[i], nodes[j])){
                adj[nodes[i]].push_back(nodes[j]);
                adj[nodes[j]].push_back(nodes[i]);
            }
        }
    }
}

int bfs(int a, int b){
    vector<int> dis(1e4, 1e9);
    int dpth = 0;
    queue<int> q; q.push(a); dis[a] = dpth;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int tmp = q.front(); q.pop();
            for(auto& child : adj[tmp]){
                if(dis[child] == 1e9){
                    q.push(child);
                    dis[child] = dpth+1;
                    if(child == b){
                        return dpth+1;
                    }
                }
            }
        }
        dpth++;
    }
    return 0;
}

void solve(){
    int a, b; cin >> a >> b;
    cout << bfs(a, b) << endl;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;

    sieve();
    for(int i = 1e3; i <= 1e4; i++){
        if(prms[i])
            nodes.push_back(i);
    }
    n = nodes.size();
    bld();

    while(t--){
        solve();
    }
    return 0;
}
