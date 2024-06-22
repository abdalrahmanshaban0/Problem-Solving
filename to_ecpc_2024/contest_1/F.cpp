/*
Problem Name : F 
Author: Abdalrahman Shaban
Date: 21/06/2024 22:21:51
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

struct monster{
    int x;
    ll h;
    bool operator < (monster obj){
        return (x < obj.x);
    }
};

void solve(){
    int n; ll d, a; cin >> n >> d >> a;
    monster arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].h;
    }
    sort(arr, arr+n);    
    ll l = 1, r = 1e15;
    ll ans = 0;
    while(l<=r){
        ll md = (l+r)/2;
        ll neg = 0;
        ll hits = md;
        queue<pair<ll, ll>> q;
        for(int i = 0; i < n; i++){
            ll hel = arr[i].h;

            while(!q.empty() && arr[i].x > q.front().first){
                neg -= q.front().second;
                q.pop();
            }
            if(!q.empty() && arr[i].x <= q.front().first){
                hel -= neg;
            }

            ll cnt = 0;
            if(hel > 0){
                cnt = (hel/a + (hel%a != 0));
            }
            hits -= cnt;

            if(cnt){
                neg += cnt*a;
                q.push({arr[i].x+2*d,cnt*a});
            }
        }
        if(hits < 0){
            l = md+1;
        }
        else{
            ans = md;
            r = md-1;
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
