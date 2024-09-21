/*
Problem Name : Static Range Minimum Queries
Author: Abdalrahman Shaban
Date: 06/09/2024 22:55:34
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

ll cmp(ll a, ll b){
  return min(a,b);
}

template <class sp> class sparseTable {
private:
  int n, m;
  sp *arr; 
  int* LG;  
  sp **tb;
  sp (*funcptr)(sp, sp);
  sp largestPWOF2(sp num) {
    int pw = 0;
    while ((1 << pw) <= num) {
      pw++;
      if ((1 << pw) > num) {
        pw--;
        break;
      }
    }
    return pw;
  }
  void precalc(){
    LG[1] = 0;
    for(int i = 2; i <= n; i++){
      LG[i] = log2(i>>1)+1;
    }
  }
public:
  sparseTable(int sz, sp *ptr, sp (*fp)(sp, sp)) {
    n = sz;
    m = log2(sz) + 1;
    arr = ptr;
    funcptr = fp;
    tb = new sp *[n];
    for (int i = 0; i < n; i++) {
      tb[i] = new sp[m];
    }
    LG = new int[n+1];
  }
  ~sparseTable() {
    for (int i = 0; i < n; i++) {
      delete[] tb[i];
    }
    delete[] tb;
  }

  void build() {
    for (int i = 0; i < n; i++) {
      tb[i][0] = arr[i];
    }
    for (int pw = 1; pw < m; pw++) {
      for (int i = 0; i + (1 << (pw - 1)) < n; i++) {
        tb[i][pw] = funcptr(tb[i][pw - 1], tb[i + (1 << (pw - 1))][pw - 1]);
      }
    }
    precalc();
  }
  // 0 index
  sp query(int l, int r) {
    int pw = LG[r - l + 1];
    return funcptr(tb[l][pw], tb[r - (1 << pw) + 1][pw]);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sparseTable<ll> stb(n, arr, cmp);
  stb.build();

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << stb.query(l, r) << '\n';
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
