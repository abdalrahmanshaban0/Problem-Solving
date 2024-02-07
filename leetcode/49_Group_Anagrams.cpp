/*
Problem Name : 49. Group Anagrams 
Author: Abdalrahman Shaban
Date: 06/02/2024 13:55:25
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, int>> v(n);
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            v[i] = {temp, i};
        }
        sort(v.begin(), v.end());
        vector<vector<string>> ans;
        vector<string> temp;
        string chk = v[0].first;
        for(int i = 0; i < n; i++){
            if(chk == v[i].first){
                temp.push_back(strs[v[i].second]);
            }
            else{
                chk = v[i].first;
                ans.push_back(temp);
                temp.clear();
                temp.push_back(strs[v[i].second]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

void solve(){
    Solution obj;
    vector<string> v = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ret = obj.groupAnagrams(v);
    for(auto& i : ret){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    Fast();
    file();
    solve() ;
    return 0;
}
