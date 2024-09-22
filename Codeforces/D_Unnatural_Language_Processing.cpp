/*
Problem Name : D. Unnatural Language Processing 
Author: Abdalrahman Shaban
Date: 26/01/2024 22:26:22
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

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string temp = s;
        unordered_map<char, int> v, c;
        int cc = 0, vv = 0;
        for(int i = 0 ;i < n; i++){
            if(s[i] == 'a' || s[i] == 'e'){
                vv++;
                v[s[i]]++;
                temp[i] = '0';
            }
            else{
                cc++;
                c[s[i]]++;
                temp[i] = '1';
            }
        }
        string ans;
        int it = 0;
        for(int i = 0; i < n-2;i++){
            if(temp[i] == '1'){
                ans += s[i];
                it++;
            }
            else{
                if(temp[i+2] == '0'){
                    ans += s[i];
                    ans += '.';
                    it++;
                }
                else{
                    ans += s[i];
                    ans += s[i+1];
                    it+=2;
                    ans += '.';
                    i++;
                }
            }
        }
        for(int i = it; i < n; i++){
            ans += s[i];
        }
        cout << ans << '\n';
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
