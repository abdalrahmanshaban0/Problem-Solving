/*
Problem Name : Q. No standard again 
Author: Abdalrahman Shaban
Date: 19/01/2024 13:41:11
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define clr(arr, x) (memset(arr, x, sizeof arr))
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<ll>
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

struct point{
    int x;
    int y;
    ll val;
};

void solve(){
    vector<vector<ll>> grid(2001, vector<ll>(2001));
    int n, q; cin >> n >> q;
    point arr[n];
    map<ll, int> mpx, mpy;
    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].val;
        mpx[arr[i].x];
        mpy[arr[i].y];
    }
   
    vector<vector<int>> v(q, vector<int>(4));
    for(int i = 0 ;i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i] = {x1, y1, x2, y2};
        mpx[x1]; mpx[x2]; mpy[y1]; mpy[y2];
    }

    int nxt = 1;
    for(auto& i : mpx){
        i.second = nxt++;
    }
    nxt = 1;
    for(auto& i : mpy){
        i.second = nxt++;
    }
    for(int i = 0 ;i < n; i++){
        grid[mpx[arr[i].x]][mpy[arr[i].y]] = arr[i].val;
    }
    for(int i = 1 ;i <= 2000; i++){
        for(int j = 1; j <= 2000; j++){
            grid[i][j] += grid[i][j-1];
        }
    }
    for(int i = 1; i <= 2000; i++){
        for(int j = 1; j<= 2000; j++){
            grid[j][i] += grid[j-1][i];
        }
    }
    for(int i = 0; i < q; i++){
        int x1 = mpx[v[i][0]], y1 = mpy[v[i][1]],
            x2 = mpx[v[i][2]], y2 = mpy[v[i][3]];
        ll sm = grid[x2][y2] - grid[x2][y1-1] - grid[x1-1][y2] + grid[x1-1][y1-1];
        cout << sm << '\n';
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
