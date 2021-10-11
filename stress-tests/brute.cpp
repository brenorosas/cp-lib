//#pragma GCC target("sse4.2")
//#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pb push_back
#define ms(v, x) memset(v, x, sizeof v)
#define td(v) v.begin(), v.end()
#define tdr(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define pii pair<int, int>
using namespace std;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

double rad(double x) { return x * pi / 180.0; }

int exp(int a, int b) {
  int res = (a != 0) % MOD;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a - b << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}