/*
Problem Name : D 
Author: Abdalrahman Shaban
Date: 02/07/2024 18:37:59
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
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

vector<ll> factorization(ll num){
    vector<ll> ret;
    for(ll i = 2; i*i <= num; i++){
        if(num%i == 0) ret.push_back(i);
        while(num % i == 0) num/=i;
    }
    if(num > 1) ret.push_back(num);
    return ret;
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



void solve(){
    ll n, t; cin >> n >> t;
    string s; cin >> s;

    vector<ll> ne; 
    ordered_set po;

    for(auto&i : ne) cin >> i;
    for(int i = 0 ;i < n; i++){
        ll val; cin >> val;
        if(s[i] == '1'){
            po.insert(val);
        }
        else{
            ne.push_back(val);
        }
    }

    ll ans = 0;
    for(auto& i : ne){
        ll l = i-t, r = i;
        ll suf = po.order_of_key(r+1);
        ll pre = po.order_of_key(l-t);
        ans += suf - pre;
    }
    cout << ans;
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
