/*
Problem Name : Monsters 
Author: Abdalrahman Shaban
Date: 27/06/2024 20:32:18
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

int dx[] = {0, 0, 1,-1, -1,-1, 1, 1};
int dy[] = {1,-1, 0, 0,  1,-1,-1,-1};

struct p{
    int x, y;
    bool operator != (p obj){
        return(x!=obj.x || y!=obj.y);
    }
};

int n, m;
char** arr;
p st;

bool valid(int i, int j){
    return(i >= 0 && j >= 0 && i < n && j < m);
}
bool isbr(int i, int j){
    return(i == n-1 || j == m-1 || i == 0 || j == 0);
}

const int inf = 1e9;
p** par;
int** dst;
string path;
const char* di = "RLDU";

void Mbfs(queue<p>& q){
    bool vis[n][m]; memset(vis, 0, sizeof(vis));
    while(!q.empty()){
        p cur = q.front(); q.pop();
        vis[cur.x][cur.y] = 1;
        for(int i = 0; i < 4; i++){
            p ne{cur.x+dx[i], cur.y+dy[i]};
            if(valid(ne.x, ne.y) && !vis[ne.x][ne.y] && arr[ne.x][ne.y] == '.'){
                dst[ne.x][ne.y] = min(dst[ne.x][ne.y], dst[cur.x][cur.y]+1);
                vis[ne.x][ne.y] = 1;
                q.push(ne);
            }
        }
    }
}

bool bfs(){
    queue<p> q; q.push(st);
    bool vis[n][m]; memset(vis, 0, sizeof(vis));
    int dpth = 1;
    while(!q.empty()){
        int sz = q.size(); 
        while(sz--){
            p cur = q.front(); q.pop();
            vis[cur.x][cur.y] = 1;
            for(int i = 0; i < 4; i++){
                p ne{cur.x+dx[i], cur.y+dy[i]};
                if(valid(ne.x, ne.y) && !vis[ne.x][ne.y] && arr[ne.x][ne.y] == '.' && dst[ne.x][ne.y] > dpth){
                    par[ne.x][ne.y] = cur;
                    arr[ne.x][ne.y] = di[i];
                    if(isbr(ne.x, ne.y)){
                        p it = ne;
                        while(it != st){
                            path.push_back(arr[it.x][it.y]);
                            it = par[it.x][it.y];
                        }
                        return true;
                    }
                    vis[ne.x][ne.y] = 1;
                    q.push(ne);
                }
            }
        }
        dpth++;
    }
    return false;
}
void solve(){
    cin >> n >> m;
    arr = new char*[n];
    par = new p*[n];
    dst = new int*[n];
    queue<p> q;
    for(int i = 0; i < n; i++){
        arr[i] = new char[m];
        par[i] = new p[m];
        dst[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            dst[i][j] = inf;
            if(arr[i][j] == 'M'){
                q.push({i,j});
                dst[i][j] = 0;
            }
            if(arr[i][j] == 'A'){
                st = {i,j};
            }
        }
    }
    if(isbr(st.x, st.y)){
        YES; cout << 0; return;
    }

    Mbfs(q);
    bool ok = bfs();
    if(!ok){
        cout << "NO";
    }
    else{
        YES;
        reverse(all(path));
        cout << path.size() << endl;
        cout << path;
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
