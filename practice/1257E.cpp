//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

vector<set<ll> > st;

ll dp[200005][3];
ll n;

ll rec(ll i, ll k) {
  if (i == n+1) return 0;
  if (dp[i][k] != -1) return dp[i][k];
  ll mx = INT_MAX;
  ll p = 0;
  if (st[k].find(i) == st[k].end()) p = 1;
  mx = min(mx, p+rec(i+1, k));
  if (k < 2)
  mx = min(mx, p+rec(i+1, k+1));
  return dp[i][k] = mx;
}

int main() {
  IOS
  #ifdef SHAN
  freopen("input.txt", "r", stdin);
  #endif
  st.resize(3);
  ll k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  n = k1+k2+k3;
  ll v;
  for (ll i = 0; i < k1; i++) {
    cin >> v;
    st[0].insert(v);
  }
  for (ll i = 0; i < k2; i++) {
    cin >> v;
    st[1].insert(v);
  }
  for (ll i = 0; i < k3; i++) {
    cin >> v;
    st[2].insert(v);
  }
  memset(dp, -1, sizeof(dp));
  ll ans = rec(1, 0);
  ans = min(ans, rec(1, 1));
  ans = min(ans, rec(1, 2));
  cout << ans << endl;
  return 0;
}
