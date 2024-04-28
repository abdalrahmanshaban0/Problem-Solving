/*
Problem Name : S - Getting Gold 
Author: Abdalrahman Shaban
Date: 28/04/2024 21:32:14
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
//           U D R L
int dx[] = {-1,1,0,0};
int dy[] = { 0,0,1,-1};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};


void dfs(char** arr, bool** vis, const int& n, const int& m, int i, int j, int& sm){
    vis[i][j] = 1;
    if(arr[i][j] == 'G') sm++;
    for(int k = 0; k < 4; k++){
        int ni = i+dx[k], nj = j+dy[k];
        if(arr[ni][nj] == 'T'){
            return;
        }
    }
    for(int k = 0; k < 4; k++){
        int ni = i+dx[k], nj = j+dy[k];
        if(!vis[ni][nj] && arr[ni][nj] != '#' && arr[ni][nj] != 'T'){
            dfs(arr, vis, n, m, ni, nj, sm);
        }
    }
}

void solve(){
    int n, m;
    while(cin >> m >> n){
        char** arr = new char*[n];
        int x = -1, y = -1;
        for(char** i = arr; i < arr+n; i++){
            *i = new char[m];
            cin >> *i;
            if(x == -1){
                for(int j = 0; j < m; j++){
                    if((*i)[j] == 'P'){
                        x = i-arr, y = j; break;
                    }
                }
            }
        }
        bool** vis = new bool*[n];
        for(bool** i = vis; i < vis+n; i++){
            *i = new bool[m];
            memset(*i, 0, m);
        }

        int ans = 0;
        dfs(arr, vis, n, m, x, y, ans);
        cout << ans << endl;

        for(char** i = arr; i < arr+n; i++){
            delete [] *i;
        }
        delete [] arr;
        for(bool** i = vis; i < vis+n; i++){
            delete [] *i;
        }
        delete [] vis;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
