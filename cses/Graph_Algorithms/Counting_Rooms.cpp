/*
Problem Name : Counting Rooms 
Author: Abdalrahman Shaban
Date: 16/06/2024 01:44:51
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
 
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) { }
    TreeNode(int v) : val(v), left(NULL), right(NULL) { }
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) { }
};
 
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
 
int dx[] = {0, 0, 1,-1, -1,-1, 1, 1};
int dy[] = {1,-1, 0, 0,  1,-1,-1,-1};
 
int n, m;
char** arr;
bool** vis;
 
bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}
 
void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int nx = i+dx[k], ny = j+dy[k];
        if(valid(nx, ny) && !vis[nx][ny] && arr[nx][ny] == '.'){
            dfs(nx, ny);
        }
    }
}
 
void solve(){
    cin >> n >> m;
    arr = new char*[n];
    vis = new bool*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new char[m];
        vis[i] = new bool[m];
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.' && !vis[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}
 
int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
