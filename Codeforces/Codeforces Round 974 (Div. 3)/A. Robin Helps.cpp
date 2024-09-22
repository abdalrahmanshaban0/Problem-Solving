#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n, k; cin >> n >> k;
  ll arr[n], ans = 0, sm = 0;

  for(int i = 0 ;i < n; i++){
    cin >> arr[i];
    if(arr[i] >= k){
      sm += arr[i];
    }
    else if(arr[i] == 0){
      if(sm){
        ans++;
        sm--;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  Fast();
  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
