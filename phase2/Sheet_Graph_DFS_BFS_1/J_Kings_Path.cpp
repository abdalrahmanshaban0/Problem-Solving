/*
Problem Name : J - King's Path 
Author: Abdalrahman Shaban
Date: 13/04/2024 12:15:26
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
int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

void solve(){
    pair<ll,ll> in, fi; cin >> in.first >> in.second >> fi.first >> fi.second;
    int nn; cin >> nn;
    map<pair<ll,ll>, bool> nodes;
    for(int i = 0; i < nn; i++){
        int r, c1, c2; cin >> r >> c1 >> c2;
        for(int j = c1; j <= c2; j++){
            nodes[make_pair(r, j)] = 1;
        }
    }

    map<pair<ll,ll>, ll> dst;
    queue<pair<ll,ll>> q;
    q.push(in);
    dst[in] = 0;
    while(!q.empty()){
        int sz = q.size();
        pair<ll,ll> cur = q.front();         
        q.pop();
        for(int i = 0; i < 8; i++){
            pair<ll,ll> pnt = {cur.first+dx[i], cur.second+dy[i]};
            if(nodes.count(pnt) == 0 || dst.count(pnt) != 0) continue;
            if(pnt.first == fi.first && pnt.second == fi.second){
                cout << dst[cur]+1; return;
            }
            dst[pnt] = dst[cur]+1;
            q.push(pnt);
        }
    }
    cout << -1; return;
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
