/*
Problem Name : C 
Author: Abdalrahman Shaban
Date: 20/04/2024 14:07:06
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

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};

void solve(){
    int n; cin >> n;
    set<pair<int, int>> st;
    int arr[n];
    for(int i = 0;i  < n; i++){
        cin >> arr[i];
        st.insert({arr[i],i});
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        if(arr[i] != (i+1)){
            auto it = st.lower_bound({i+1,0});
            int idx = (*it).second;
            ans.push_back({i+1, idx+1});
            st.erase({arr[i],i});
            st.erase(it);
            st.insert({arr[i], idx});
            st.insert({arr[idx], i});
            swap(arr[i], arr[idx]);
        }
    }
    cout << ans.size() << endl;
    for(auto&i:ans) cout << i.first << ' ' << i.second << endl;
}

int main() {
    Fast();
    file();
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
