/*
Problem Name : R - Deciding victory in Go 
Author: Abdalrahman Shaban
Date: 12/07/2024 19:16:31
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

int dx[] = {0, 0, 1,-1, -1,-1, 1, 1};
int dy[] = {1,-1, 0, 0,  1,-1,-1,-1};

const int n = 9;
char arr[n][n];
bool vis[n][n];

bool valid(int i, int j){
    return(i >= 0 && j >= 0 && i < n && j < n);
}
enum sur {notyet, notvalid, black, white};

int dfs(int i, int j, sur& ind){
    vis[i][j] = 1;
    int ret = 1;
    for(int k = 0; k < 4; k++){
        int nx = i+dx[k], ny = j+dy[k];
        if(valid(nx, ny) && !vis[nx][ny]){
            if(arr[nx][ny] == '.'){
                ret += dfs(nx, ny, ind);
            }
            else if(ind != notvalid){
                if(ind == notyet){
                    ind = (arr[nx][ny] == 'X' ? black : white);
                }
                else if(ind == black){
                    ind = (arr[nx][ny] == 'O' ? notvalid : ind);
                }
                else if(ind == white){
                    ind = (arr[nx][ny] == 'X' ? notvalid : ind);
                }
            }
        }
    }
    return ret;
}

void solve(){
    int b = 0, w = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            b += (arr[i][j] == 'X');
            w += (arr[i][j] == 'O');
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '.' && !vis[i][j]){
                sur chk = notyet;
                int val = dfs(i,j,chk);
                if(chk == black) b += val;
                else if(chk == white) w += val;
            }
        }
    }
    cout << "Black " << b << ' ' << "White " << w << endl;
}

int main() {
    Fast();
    file();
    int t; cin >> t;
    while(t--)
        solve(); 
    return 0;
}
