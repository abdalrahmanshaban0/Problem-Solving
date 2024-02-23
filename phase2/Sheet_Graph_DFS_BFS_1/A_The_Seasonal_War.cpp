/*
Problem Name : A - The Seasonal War 
Author: Abdalrahman Shaban
Date: 22/02/2024 19:52:37
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

bool valid(int i, int j){
    return(i >= 0 && j >= 0 && i < n && j < n);
}

int arr[26][26];
struct node{
    int x;
    int y;
};
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

vector<vector<bool>> vis(26, vector<bool>(26));

void dfs(node nd){
    vis[nd.x][nd.y] = 1;
    for(int i = 0 ;i < 8; i++){
        node child = {nd.x+dx[i], nd.y+dy[i]};
        if(valid(child.x, child.y) && !vis[child.x][child.y] && arr[child.x][child.y]){
            dfs(child);
        }
    }
}

void clr(){
    for(int i = 0 ;i < 26 ;i++){
        for(int j = 0 ;j < 26; j++){
            vis[i][j] = 0;
        }
    }
}

void solve(){
    memset(arr, 0, sizeof(arr));
    int tst = 1;
    while(cin >> n){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ;j < n; j++){
                char c; cin >> c;
                arr[i][j] = (c-'0');
            }
        }
        int ans = 0;
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && arr[i][j]){
                    node cur = {i, j};
                    dfs(cur);
                    ans++;
                }
            }
        }
        cout << "Image number " << tst++ << " contains " << ans << " war eagles.\n";
        clr();
    }
}

int main() {
    Fast();
    file();
    int t = 1;
    //    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
