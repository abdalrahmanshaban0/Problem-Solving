#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/

// defines & constants
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

// structures & classes
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(NULL), right(NULL) {}
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};
struct edge {
  int from, to;
  ll w; // from, if you want to backtrack the path
  edge() : from(-1), to(-1), w(-1) {}
  edge(int t, ll we) : to(t), w(we) {}
  edge(int f, int t, ll we) : from(f), to(t), w(we) {}
  bool operator<(const edge &obj) const {
    return (w > obj.w); // return greater to make the smaller is the top
  }
};

// functions
template <typename... Args> void print(Args... args) {
  (cout << ... << args) << '\n';
}
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) {
  if (r == 0 || n == r)
    return 1;
  return nCr(n - 1, r - 1) * n / r;
}
vector<ll> primefactors(ll num) {
  vector<ll> ret;
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0)
      ret.push_back(i);
    while (num % i == 0)
      num /= i;
  }
  if (num > 1)
    ret.push_back(num);
  return ret;
}
vector<ll> divisors(ll num) {
  vector<ll> ret;
  for (ll i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      ret.push_back(i);
      if (num / i != i) {
        ret.push_back(num / i);
      }
    }
  }
  return ret;
}
ll fpower(ll x, ll y, ll M) {
  if (y == 0)
    return 1;
  ll val = fpower(x, y / 2, M) % M;
  val = (val * val) % M;
  return (val * (y & 1 ? x : 1)) % M;
}
ll modInverse(ll A, ll M) {
  ll g = gcd(A, M);
  if (g != 1)
    return -1;
  return fpower(A, M - 2, M);
}
vector<pair<int, int>> Merge_intervals(vector<pair<int, int>> &v) {
  sort(v.begin(), v.end());
  vector<pair<int, int>> res;
  for (auto &i : v) {
    if (res.empty()) {
      res.push_back(i);
    } else {
      int l = i.first;
      int r = i.second;
      int x = res.back().first;
      int y = res.back().second;
      if (l <= y || (l <= x && r >= y)) {
        res.pop_back();
        res.emplace_back(min(l, x), max(r, y));
      } else {
        res.emplace_back(l, r);
      }
    }
  }
  return res;
}

string string_gcd(string str1, string str2) {
  if (str1 + str2 == str2 + str1) {
    return str1.substr(0, gcd(str1.size(), str2.size()));
  } else {
    return "";
  }
}
int countLattice(int r) {
  if (r <= 0)
    return 0;
  int result = 4;
  for (int x = 1; x < r; x++) {
    int ySquare = r * r - x * x;
    int y = sqrt(ySquare);
    if (y * y == ySquare)
      result += 4;
  }
  return result;
}

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

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, -1};

void solve() {}

int main() {
  Fast();
  file();
  solve();
  return 0;
}
