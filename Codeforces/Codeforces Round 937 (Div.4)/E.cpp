/*
Problem Name : E 
Author: Abdalrahman Shaban
Date: 28/03/2024 18:52:49
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

const int N = 2e5+1;
vector<vector<int>> dvs(N);

void getdvs(vector<int>& dvs, int n){
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            dvs.push_back(i);
            if(n/i != i)
                dvs.push_back(n/i);
        }
    }
}

void solve(){
    int n; string s; cin >> n >> s;
    sort(all(dvs[n]));
    for(auto& i : dvs[n]){
        string sub = s.substr(0, i), sub1 = s.substr(n-i, i);
        int cnt = 0, cnt1 = 0;
        for(int j = 0; j < i; j++){
            for(int k = j+i; k < n; k+=i){
                if(sub[j] != s[k]){
                    cnt++;
                    if(cnt == 2) break;
                }
            }
            for(int k = n-i+j; k >= 0; k-=i){
                if(sub1[j] != s[k]){
                    cnt1++;
                    if(cnt1 == 2) break;
                }
            }
        }
        if(cnt <= 1 || cnt1 <= 1){
            cout << i << endl; return;
        }
    }
}

int main() {
    Fast();
    file();

    for(int i = 1; i < N; i++){
        getdvs(dvs[i], i);
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
