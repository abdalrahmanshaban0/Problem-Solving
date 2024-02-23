/*
Problem Name : B - Marcus 
Author: Abdalrahman Shaban
Date: 22/02/2024 21:11:00
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

string chk = "IEHOVA#";

int n, m;
char arr[10][10];

int dx[] = {0, 0, -1};
int dy[] = {1, -1, 0};

bool valid(int i, int j){
    return(i >= 0 &&  j >= 0 && i < n && j < m);
}

void dfs(int i, int j, int it){
    if(it == chk.size()) return;
    for(int k = 0 ;k < 3; k++){
        int x = i+dx[k], y = j+dy[k];
        if(valid(x, y) && arr[x][y] == chk[it]){
            if(k == 0){
                cout << "right";
            }
            else if(k == 1){
                cout << "left";
            }
            else{
                cout << "forth";
            }
            if(arr[x][y] != '#') cout << ' ';
            dfs(x, y, it+1);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '@'){
                dfs(i, j, 0);
                cout << endl;
                return;
            }
        }
    }
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
