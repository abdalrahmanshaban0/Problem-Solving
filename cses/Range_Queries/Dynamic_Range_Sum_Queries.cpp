/*
Problem Name : Dynamic Range Sum Queries
Author: Abdalrahman Shaban
Date: 07/09/2024 13:50:14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

const int N = sqrt(2e5)+1;

template <class T> class SQRT_Decomposition {
private:
  T *arr;
  int sz;
  int MAXblockSize;
  vector<vector<T>> blk;
  vector<T> blksm;

public:
  SQRT_Decomposition(int n, T *arrptr) {
    sz = n;
    arr = arrptr;
    MAXblockSize = N;
    blk.resize(N);
    blksm.resize(N);
    for (int i = 0; i < sz; i++) {
      blk[i / MAXblockSize].push_back(arr[i]);
      blksm[i / MAXblockSize] += arr[i];
    }
  }
  void update(int idx, T nval) {
    blk[idx / MAXblockSize][idx % MAXblockSize] = nval;
    blksm[idx / MAXblockSize] -= arr[idx];
    blksm[idx / MAXblockSize] += nval;
    arr[idx] = nval;
  }
  T query(int l, int r) {
    T ans = 0;
    while (l <= r) {
      if (l % MAXblockSize == 0 && l + MAXblockSize <= r) {
        ans += blksm[l / MAXblockSize];
        l += MAXblockSize;
      } else {
        ans += arr[l++];
      }
    }
    return ans;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  SQRT_Decomposition<ll> blks(n, arr);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx;
      ll val;
      cin >> idx >> val;
      blks.update(--idx, val);
    }
    else{
      int l, r; cin >> l >> r;
      cout << blks.query(--l,--r) << '\n';
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
