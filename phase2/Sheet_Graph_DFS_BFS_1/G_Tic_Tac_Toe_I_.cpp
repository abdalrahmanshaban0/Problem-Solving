/*
Problem Name : G - Tic-Tac-Toe ( I ) 
Author: Abdalrahman Shaban
Date: 24/03/2024 20:49:49
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
const int N = 3;
char arr[N][N];
char emp[N][N];
bool ok;

enum player {X, O};

bool chkwin(){
    for(int i = 0 ; i < N; i++){
        int cntx = 0, cnto = 0;
        for(int j = 0; j < N; j++){
            if(emp[i][j] == 'X') cntx++;
            else if(emp[i][j] == 'O') cnto++;
        }
        if(cntx == 3 || cnto == 3){
            return 1;
        }
    }
    for(int j = 0; j < N; j++){
        int cntx = 0, cnto = 0;
        for(int i = 0; i < N; i++){
            if(emp[i][j] == 'X') cntx++;
            else if(emp[i][j] == 'O') cnto++;
        }
        if(cntx == 3 || cnto == 3){
            return 1;
        }
    }
    int cntx = 0, cnto = 0;
    for(int i = 0 ;i < N; i++){
        if(emp[i][i] == 'X') cntx++;
        else if(emp[i][i] == 'O') cnto++;
    }
    if(cntx == 3 || cnto == 3){
        return 1;
    }
    cntx = 0, cnto = 0;
    for(int i = N-1; i >= 0; i--){
        if(emp[i][i] == 'X') cntx++;
        else if(emp[i][i] == 'O') cnto++;
    }
    return (cntx == 3 || cnto == 3);
}

void rec(player turn){
    if(ok) return;
    //input grid equal
    bool eq = 1;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            if(emp[i][j] != arr[i][j]){
                eq = 0;
                break;
            }
        }
        if(!eq) break;
    }
    if(eq){
        ok = 1;
        return;
    }
    //someone wins
    if(chkwin()) return;
    //filled grid
    bool chk = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            if(emp[i][j] == '.'){
                chk = 0;
                break;
            }
        }
        if(!chk) break;
    }
    if(chk){
        return;
    }

    if(turn == X){
        for(int i = 0; i < N; i++){
            for(int j = 0;j < N; j++) if(emp[i][j] == '.'){
                emp[i][j] = 'X';
                rec(O);
                emp[i][j] = '.';
            }
        }
    }
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0;j < N; j++) if(emp[i][j] == '.'){
                emp[i][j] = 'O';
                rec(X);
                emp[i][j] = '.';
            }
        }
    }
}

void solve(){
    ok = 0;
    for(int i = 0 ;i < N; i++){
        for(int j=  0; j < N ; j++){
            emp[i][j] = '.';
        }
    }
    for(int i = 0 ;i < N; i++){
        for(int j=  0; j < N ; j++){
            cin >> arr[i][j];
        }
    }
    rec(X);
    if(ok) cout << "yes";
    else cout << "no";
    cout << endl;
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
