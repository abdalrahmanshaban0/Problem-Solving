// Problem: B: Prime Subtractorization
// Contest: Meta Hacker Cup 2024 Round 1
// URL:
// https://www.facebook.com/codingcompetitions/hacker-cup/2024/round-1/problems/B?source=facebook
// Start: Sat 05 Oct 2024 10:15:39 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

const ll MX = 10e6;
vector<bool> pr(MX + 1, 1);
vector<ll> prs;
vector<int> ps;

vector<int> v(MX + 1, 0);

void sive() {
  pr[0] = 0;
  pr[1] = 0;
  for (ll i = 2; i * i <= MX; i++) {
    if (pr[i]) {
      prs.push_back(i);
      for (ll j = 2 * i; j <= MX; j += i) {
        pr[j] = 0;
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  cout << v[n] << '\n';
}

int main() {
  Fast();
  sive();
  v[5] = 2;
  for (int i = 6; i <= MX; i++) {
    if(pr[i] && pr[i-2]){
      v[i]++;
    }
    v[i] += v[i-1];
  }
  int ts;
  cin >> ts;
  for (int t = 1; t <= ts; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
