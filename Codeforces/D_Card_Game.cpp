/*
Problem Name : D. Card Game 
Author: Abdalrahman Shaban
Date: 21/02/2024 20:14:10
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



void solve(){
    int n; char trmp; cin >> n >> trmp;
    vector<string> v(2*n);
    map<char, vector<char>> mp;
    vector<char> trmps;
    for(auto& i : v){
        cin >> i;
        if(i[1] == trmp){
            trmps.push_back(i[0]);
        }
        else{
            mp[i[1]].push_back(i[0]);
        }
    }

    sort(all(trmps));
    vector<pair<string, string>> ans;
    int nd = 0;

    for(auto& i : mp){
        char c = i.first;
        vector<char>& v = i.second;
        
        if((int)v.size() & 1) nd++;
        sort(all(v));
        
        for(int j = 1; j < v.size(); j+= 2){
            if(v[j] == v[j-1]){
                nd++;
                break;
            }
            string s1;  s1 += v[j];s1 += c;
            string s2; s2 += v[j-1];s2 += c; 
            ans.push_back({s2, s1});
            i.second[j] = '0';
            i.second[j-1] = '0';
        }
    }
    if(nd > trmps.size()){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int it = 0;
    for(auto& i : mp){
        char c = i.first;
        vector<char>& v = i.second;
        for(int j = 0 ; j < v.size(); j++){
            if(v[j] != '0'){
                string s1;  s1 += trmps[it++];s1 += trmp;
                string s2;  s2 += v[j];s2 += c;               
                ans.push_back({s2, s1});
            }
        }
    }

    while(it+1 < trmps.size()){
        if(trmps[it] < trmps[it+1]){
            string s1;  s1 += trmps[it+1];s1 += trmp;
            string s2;  s2 += trmps[it];s2 += trmp;
            ans.push_back({s2, s1});
        }
        else if(trmps[it] == trmps[it+1]){
            cout << "IMPOSSIBLE\n";
            return;
        }
        it+=2;
    }
    for(auto& i : ans){
        cout << i.first << ' ' << i.second << endl;
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

