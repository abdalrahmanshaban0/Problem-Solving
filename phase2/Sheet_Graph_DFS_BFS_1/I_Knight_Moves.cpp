/*
Problem Name : I - Knight Moves 
Author: Abdalrahman Shaban
Date: 22/02/2024 23:38:54
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct p{
    int x, y;
};

bool valid(int i, int j){
    return (i >= 1 && j >= 1 && i <= 8 && j <= 8);
}

int dx[] = {-1, -1, 1, 1, 2, 2, -2, -2};
int dy[] = {2, -2, -2, 2, 1, -1, 1, -1};

vector<vector<vector<p>>> adjList(9, vector<vector<p>>(9));

void graph_representation(p node){
    for(int dir = 0; dir < 8; dir++){
        int x = node.x + dx[dir], y = node.y + dy[dir];
        if(valid(x, y)){
            adjList[node.x][node.y].push_back({x, y});
        }
    }
}

p from, to;

vector<vector<int>> dis(9, vector<int>(9, 1e9));
void BFS(p src){
    queue<p> q; 
    q.push(src); dis[src.x][src.y] = 0;
    int dpth = 0;
    while(!q.empty()){
        int sz = q.size();
        p cur;
        while(sz--){
            cur = q.front(); q.pop();
            for(auto& i : adjList[cur.x][cur.y]){
                if(dis[i.x][i.y] == 1e9){
                    q.push(i); dis[i.x][i.y] = dpth+1;
                }
            }
        }
        dpth++;
    }
}

void solve(){   //BFS
    string s, ss; 
    for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) graph_representation({i, j});
    while(cin >> s >> ss){
        from = {(s[1]-'0'), (s[0]-'a'+1)};
        to = {(ss[1]-'0'), (ss[0]-'a'+1)};

        BFS(from) ;
        cout << "To get from " << s << " to " << ss << " takes " << dis[to.x][to.y] << " knight moves.\n";
        dis.clear(); dis.resize(9, vector<int>(9, 1e9));
    }
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
