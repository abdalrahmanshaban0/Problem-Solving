/*
Problem Name : H 
Author: Abdalrahman Shaban
Date: 18/06/2024 17:26:00
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
int n, m;
int cst[26];
string a, b;
int dp[2001][2001];

int rec(int i, int j){
    if(i == n || j == m){
        return 0;
    }
    int& ret = dp[i][j];
    if(~ret) return ret;
    ret = 0;
    if(a[i] == b[j]){
        ret = max(ret, cst[a[i]-'a'] + rec(i+1, j+1));
    }
    else{
        ret = max(ret, max(rec(i+1, j), rec(i, j+1)));
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < 26; i++){
        cin >> cst[i];
    }
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << rec(0,0); 
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
