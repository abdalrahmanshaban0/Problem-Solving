/*
Problem Name : P - Continents 
Author: Abdalrahman Shaban
Date: 21/05/2024 14:01:35
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
void vin(vector<ll>& v) {for(auto& i : v) cin >> i;}

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

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//int dx[8] = {0,0,1,-1,-1,-1,1,1};
//int dy[8] = {1,-1,0,0,1,-1,-1,-1};

char arr[20][20];
int n, m;
char h;

bool valid(int i, int j){
    return(i >= 0 && j >= 0 && i < n && j < m);
}
int fixy(int y){
    if(y >= m) return 0;
    if(y < 0) return m-1;
    return y;
}
void dfs(vector<vector<bool>>& vis, int i, int j, int& cnt){
    vis[i][j] = 1;
    cnt++;
    for(int k = 0; k < 4; k++){
        int nx = i+dx[k], ny = fixy(j+dy[k]);
        if(valid(nx, ny)){
            if(!vis[nx][ny] && arr[nx][ny] == h){
                dfs(vis, nx, ny, cnt);
            }
        }
    }
}

void solve(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }
        int x, y; cin >> x >> y;
        h = arr[x][y];
        vector<vector<bool>> vis(n, vector<bool>(m));

        int mx = 0;
        dfs(vis, x, y, mx);
        mx = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == h && !vis[i][j]){
                    int tot = 0;
                    dfs(vis, i, j, tot);
                    mx = max(mx, tot);
                }
            }
        }
        cout << mx << endl;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
