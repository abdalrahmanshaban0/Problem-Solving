/*
Problem Name : N - The Tree Root 
Author: Abdalrahman Shaban
Date: 07/06/2024 19:42:08
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

//int dx[] = {0, 0, 1,-1, -1,-1, 1, 1};
//int dy[] = {1,-1, 0, 0,  1,-1,-1,-1};

vector<vector<int>> adj;
const int N = 5001;
int dp[N][N];
int dfs(int root, int parent){
    int& max_dist = dp[root][parent];
    if(max_dist){
        return max_dist;
    }
    for(auto& child : adj[root]){
        if(child != parent){
            max_dist = max(max_dist, 1 + dfs(child, root));
        }
    }
    return max_dist;
}

void solve(){
    int n; 
    while(cin >> n){
        adj.resize(n); 
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            int m; cin >> m;
            for(int j = 0; j < m; j++){
                int x; cin >> x;
                --x;
                adj[i].push_back(x);
            }
        }

        int mn = n, mx = 0;
        for(int i = 0; i < n; i++){
            int dst = dfs(i, i);
            mn = min(mn, dst);
            mx = max(mx, dst);
        }

        vector<int> w, b;
        for(int i = 0; i < n; i++){
            if(dp[i][i] == mn) b.push_back(i+1);
            else if(dp[i][i]==mx) w.push_back(i+1);
        }

        cout << "Best Roots  : ";
        int cnt = 0;
        for(auto& i : b){
            if(cnt++) cout << ' ';
            cout << i;
        } cout << endl;
        cout << "Worst Roots : ";
        cnt = 0;
        for(auto& i : w){
            if(cnt++) cout << ' ';
            cout << i;
        } cout << endl;
        adj.clear();
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
