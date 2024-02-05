/*
Problem Name : 76. Minimum Window Substring 
Author: Abdalrahman Shaban
Date: 05/02/2024 00:36:25
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

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> tmp, mp;
        for(auto& k : t) tmp[k]++;

        int l = 0;
        int mnln = n+1, ln = t.size(), st = 0;
        
        int cnt = 0;
        for(int r = 0; r < n ;r++){
            if(tmp.count(s[r])==0) continue;
            mp[s[r]]++;
            if(mp[s[r]] <= tmp[s[r]]) cnt++;
            if(cnt == ln){
                while(tmp.count(s[l]) == 0 || mp[s[l]] > tmp[s[l]]){
                    if(mp.count(s[l]) != 0) mp[s[l]]--;
                    l++;
                }
                if(mnln > r-l+1){
                    mnln = r-l+1;
                    st = l;;
                }
            }
        }
        if(mnln == n+1) return "";
        return s.substr(st, mnln);
    }
};


void solve(){
    Solution obj;
    string s = "cabwefgewcwaefgcf", t = "cae";
    cout << obj.minWindow(s, t);
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
