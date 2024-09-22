#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  ll n, k;
  cin >> n >> k;
  if(n > k){
    if(((n-k+1)*k + k*(k-1LL)/2LL) & 1){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
    }
  }
  else{
    if((n*(n+1LL)/2LL)&1){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
    }
  }
}

int main() {
  Fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
