/*
Problem Name : Dynamic Range Minimum Queries
Author: Abdalrahman Shaban
Date: 13/09/2024 22:34:32
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(s) s.begin(), s.end()
#define inf LONG_LONG_MAX
void Fast();
 
struct node {
  ll mn;
  node *left;
  node *right;
  node() : mn(inf), left(nullptr), right(nullptr) {}
  void change(ll x) { mn = x; }
};
 
class segmentTree {
  node *root;
  int treeSize;

  ll merge(ll a, ll b) { return min(a, b); }
  void update(int idx, ll val, node *nd, int lx, int rx) {
    if (lx == rx) {
      nd->change(val);
      return;
    }
    int md = (lx+rx)/2;
    if (idx <= md) {
      update(idx, val, nd->left, lx, md);
    } else {
      update(idx, val, nd->right, md+1, rx);
    }
    nd->mn = merge(nd->left->mn, nd->right->mn);
  }
  ll query(int l, int r, node *nd, int lx, int rx) {
    if (l <= lx && r >= rx) {
      return nd->mn;
    }
    if (lx > r || rx < l) {
      return inf;
    }
    int md = (lx + rx)/2;
    ll lf = query(l, r, nd->left, lx, md);
    ll rt = query(l, r, nd->right, md+1, rx);
    return merge(lf, rt);
  }
 
public:
  segmentTree(int sz) {
    treeSize = 1;
    while (treeSize < sz) {
      treeSize *= 2;
    }
    root = new node;
    queue<node*> q;
    q.push(root);
    int it = 1, n = 2*treeSize-1;
    while(it < n){
      node* cur = q.front();
      q.pop();
      if(it < n){
        cur->left = new node;
        q.push(cur->left);
        it++;
      }
      if(it < n){
        cur->right = new node;
        q.push(cur->right);
        it++;
      }
    }
  }
  void set(int idx, ll val) { update(idx, val, root, 0, treeSize-1); }
  ll get(int l, int r) { return query(l, r, root, 0, treeSize-1); }
};
 
void solve() {
  int n, q;
  cin >> n >> q;
  ll arr[n];
  segmentTree sg(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sg.set(i, arr[i]);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx; ll val;
      cin >> idx >> val;
      idx--;
      sg.set(idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << sg.get(l, r) << '\n';
    }
  }
}
 
int main() {
  Fast();
  solve();
 
  return 0;
}
 
void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
