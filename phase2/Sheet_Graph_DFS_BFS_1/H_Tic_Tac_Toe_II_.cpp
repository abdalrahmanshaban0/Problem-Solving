/*
Problem Name : H - Tic-Tac-Toe ( II ) 
Author: Abdalrahman Shaban
Date: 10/04/2024 21:14:55
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
    cin.tie(NULL);
    cout.tie(NULL);
}

bool anyEnding(string& s){
    if(count(all(s), '.') == 0) return 1;
    for(int i = 0; i+2 < 9; i+=3){
        if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i]!='.') return 1;
    }
    for(int i = 0; i < 3; i++){
        if(s[i]==s[i+3]&&s[i]==s[i+6]&&s[i]!='.') return 1;
    }
    if(s[0]==s[4]&&s[4]==s[8]&&s[0]!='.') return 1;
    if(s[2]==s[4]&&s[4]==s[6]&&s[2]!='.') return 1;
    return 0;
}

void solve(string& s){
    queue<pair<string, bool>> q;
    q.push({".........", 1});
    while(!q.empty()){
        pair<string, int> temp = q.front();
        q.pop();
        if(anyEnding(temp.first)){
            if(temp.first == s){
                cout << "valid\n"; return;
            }
            continue;
        }
        for(int i = 0; i < 9; i++){
            if(temp.first[i] == '.'){
                temp.first[i] = (temp.second ? 'X' : 'O');
                if(temp.first[i] == s[i])
                    q.push({temp.first, !temp.second});
                temp.first[i] = '.';
            }
        }
    }
    cout << "invalid\n";
}

int main() {
    Fast();
    file();
    string s;
    while(true){
        cin >> s;
        if(s[0] == 'e') break;
        if(s == "........."){
            cout << "invalid\n";
        }
        else solve(s);
    } 

    return 0;
}
