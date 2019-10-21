//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

ll n;
vector<ll> vc;

ll dp[5009][5009];

ll rec(ll i1, ll i2) {
  if (dp[i1][i2] != -1) return dp[i1][i2];
  if (i1 == n) return dp[i1][i2] = 0;
  i2 = min(i2, vc[i1]+1);
  if (i2 > vc[i1]) return dp[i1][i2] = rec(i1+1, i2);
  if (i2 > n) return dp[i1][i2] = 1+rec(i1+1, i2);
  ll ans = INT_MAX;
  ans = min(ans, 1+rec(i1, i2+1));
  ans = min(ans, 1+rec(i1+1, i2));
  return dp[i1][i2] = ans;
}

int main() {
  IOS
  #ifdef SHAN
  freopen("input.txt", "r", stdin);
  #endif
  cin >> n;
  vc.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> vc[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 1) << endl;
  return 0;
}
