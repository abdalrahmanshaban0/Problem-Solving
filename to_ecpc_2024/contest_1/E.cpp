/*
Problem Name : E 
Author: Abdalrahman Shaban
Date: 19/06/2024 20:41:31
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

map<ll, int> mp;
void factorization(ll num){
    for(ll i = 2; i*i <= num; i++){
        int p = 0;
        while(num % i == 0){
            num /= i;
            p++;
        }
        if(p)
            mp[i] = max(mp[i], p);
    }
    if(num > 1){
        mp[num] = max(mp[num], 1);
    }
}


ll fpower(ll x, ll y, ll M){
    if(y == 0) return 1;
    ll val = fpower(x, y/2, M) % M;
    val = (val*val)%M;
    return (val*(y&1 ? x : 1))%M;
}


ll modInverse(ll A, ll M){
    ll g = gcd(A, M);
    if (g != 1) return -1;
    return fpower(A, M - 2, M);
}

void solve(){
    int n; cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        factorization(arr[i]);
    }
    ll  lol = 1;
    for(auto& i : mp){
        ll val = fpower(i.first, i.second, MOD);
        lol = (lol*val)%MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (lol%MOD*modInverse(arr[i], MOD)%MOD)%MOD;
        ans %= MOD;
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
