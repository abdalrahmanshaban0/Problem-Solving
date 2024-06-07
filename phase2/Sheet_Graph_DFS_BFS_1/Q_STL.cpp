/*
Problem Name : Q - STL 
Author: Abdalrahman Shaban
Date: 06/06/2024 21:24:13
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

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};

string ans;
bool ok = 1;
void chk(queue<int>& q){
    if(q.empty()){
        ok = 0; return;
    }
    int cur = q.front(); q.pop();
    if(cur){
        ans += "int";
    }
    else{
        ans += "pair<";
        chk(q);
        ans += ',';
        chk(q);
        ans += '>';
    }
}

void solve(){
    int n; cin >> n;
    string s;
    queue<int> q;
    while(cin >> s){
        if(s == "pair") q.push(0);
        else q.push(1);
    }
    chk(q);
    if(!q.empty() || !ok)
        cout << "Error occurred";
    else 
        cout << ans;
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
