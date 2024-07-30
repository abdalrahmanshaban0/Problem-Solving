/*
Problem Name : Y - Jugs 
Author: Abdalrahman Shaban
Date: 12/07/2024 21:02:25
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

vector<ll> primefactors(ll num){
    vector<ll> ret;
    for(ll i = 2; i*i <= num; i++){
        if(num%i == 0) ret.push_back(i);
        while(num % i == 0) num/=i;
    }
    if(num > 1) ret.push_back(num);
    return ret;
}
vector<ll> divisors(ll num){
    vector<ll> ret;
    for(ll i = 1; i*i <= num; i++){
        if(num%i == 0){
            ret.push_back(i);
            if(num/i != i){
                ret.push_back(num/i);
            }
        }
    }
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
struct edge{
	int from, to; ll w; //from, if you want to backtrack the path
    edge() : from(-1), to(-1), w(-1) { }
	edge(int t, ll we) : to(t), w(we) { }
	edge(int f, int t, ll we) : from(f), to(t), w(we) { }
	bool operator < (const edge& obj) const {
		return(w > obj.w);  //return greater to make the smaller is the top
	}
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

int a, b, n;
const char* s[6] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};
enum op    {fill_a,  fill_b,   emp_a,    emp_b,    pour_ab,   pour_ba};

bool ok = 0;
vector<const char*> ans;
bool vis[1001][1001];

bool rec(int x, int y){
    if(y == n){
        return true;
    }
    vis[x][y] = 1;
    vector<pair<int,int>> adj;
    adj.push_back({a,y});
    adj.push_back({x,b});
    adj.push_back({0,y});
    adj.push_back({x,0});
    int nb = min(b, x+y);
    int na = x+y-nb;
    adj.push_back({na,nb});
    na = min(a,x+y);
    nb = x+y-na;
    adj.push_back({na,nb});

    for(int i = 0; i < adj.size(); i++){
        if(!vis[adj[i].first][adj[i].second]){
            if(rec(adj[i].first, adj[i].second)){
                ans.push_back(s[i]);
                return true;
            }
        }
    }

    return false;
}


void solve(){
    while(cin >> a >> b >> n){
        memset(vis,0,sizeof(vis));
        rec(0,0);
        reverse(all(ans));
        for(auto& i : ans){
            cout << i << endl;
        }
        cout << "success\n";
        ok = 0;
        ans.clear();
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
