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

int dx[] = {1, 0, 0,-1, -1,-1, 1, 1};
int dy[] = {0,-1, 1, 0,  1,-1,-1,-1};

struct p{
    int x;
    int y;
    bool operator == (p obj){
        return (x == obj.x && y == obj.y);
    }
    bool operator != (p obj){
        return (x != obj.x || y != obj.y);
    }
};

int n, m;
char** arr;
p st, ed;
bool** vis;

bool valid(p nd){
    return(nd.x >= 0 && nd.y >= 0 && nd.x < n && nd.y < m);
}

const char* di = "DLRU";

bool bfs(p nd){
    queue<p> q;
    q.push(nd);
    while(!q.empty()){
        p cur = q.front(); 
        q.pop();
        for(int i = 0; i < 4; i++){
            p nei = {cur.x+dx[i], cur.y+dy[i]};
            if(nei == ed) return true;
            if(valid(nei) && arr[nei.x][nei.y] == '.'){
                arr[nei.x][nei.y] = di[i];
                q.push(nei);
            }
        }
    }
    return false;
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
            if(arr[i][j] == 'A'){
                st = {i, j};
            }
            else if(arr[i][j] == 'B'){
                ed = {i, j};
            }
            vis[i][j] = 0;
        }
    }
    bool ok = bfs(st);
    if(!ok){
        cout << "NO";
    }
    else{
        YES;
        p it = ed;
        string path;
        while(it != st){
            if(arr[it.x][it.y] == 'B'){
                for(int k = 0; k < 4; k++){
                    p to = {it.x+dx[k], it.y+dy[k]};
                    if(to == st){
                        cout << 1 << endl << di[3-k]; return;
                    }
                    if(valid(to) && arr[to.x][to.y] != '.' && arr[to.x][to.y] != '#'){
                        it = to;
                        path.push_back(di[3-k]);
                        break;
                    }
                }
            }
            else{
                path += arr[it.x][it.y];
                if(arr[it.x][it.y] == 'U'){
                    it.x++;
                }
                else if(arr[it.x][it.y] == 'D'){
                    it.x--;
                }
                else if(arr[it.x][it.y] == 'L'){
                    it.y++;
                }
                else if(arr[it.x][it.y] == 'R'){
                    it.y--;
                }
            }
        }
        reverse(all(path));
        cout << path.size() << '\n' << path;
    }

}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
