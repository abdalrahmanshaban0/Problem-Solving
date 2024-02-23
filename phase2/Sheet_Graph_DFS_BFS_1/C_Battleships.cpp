/*
Problem Name : C - Battleships 
Author: Abdalrahman Shaban
Date: 22/02/2024 21:46:34
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

int n;
char arr[101][101];
bool vis[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i+dx[k], y = j+dy[k];
        if(valid(x, y) && !vis[x][y] && (arr[x][y] == 'x' || arr[x][y] == '@')){
            dfs(x, y);
        }
    }
}
void solve(){
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j < n; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j  < n ;j++){
            if(!vis[i][j] && arr[i][j] == 'x'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    int t = 1;
    int tst = 1;
    cin >> t;
    while(t--){
        cout << "Case " << tst++ << ": "; 
        solve(); 
        cout << endl;
    }
    return 0;
}
