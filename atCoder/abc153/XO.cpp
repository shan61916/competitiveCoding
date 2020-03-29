//verma_ankit484

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;
//using namespace __gnu_pbds;

//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

vector<vector<ll>> adj;
vector<vector<ll>> vc;

ll mx, nd;
ll done;
void dfs(ll s, ll p, ll d) {
	done++;  
  if (d > mx) {
    mx = d;
    nd = s;
  }
  for (auto i : vc[s]) {
    if (i == p) continue;
    dfs(i, s, d+1);
  }
}

int main() {
  // IOS
  // #ifdef AV
  // freopen("input.txt", "r", stdin);
  // #endif
  ll n;
  cin >> n;
  adj.resize(n);
  for (ll i = 0; i < n-1; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  ll tot = (1ll << n) - 1;
  vector<ll> ans(n+1, 0);
  for (ll i = 1; i <= tot; i++) {
    ll mp[n+1] = {0};
    for (ll j = 0; j < n; j++) {
      if (i & (1ll << j)) {
        mp[j] = 1;
      }
    }
    vc.clear();
    vc.resize(n);
    ll st = -1;
    mx = 0;
    for (ll k = 0; k < n; k++) {
      if (mp[k] == 0) continue;
      for(auto it: adj[k]) {
      	if(it != k and mp[it]) {
      		vc[it].push_back(k);
      		vc[k].push_back(it);
      	}
      }
    }
    if (st == -1) continue;
    done = 0;
    dfs(st, -1, 0);
    ll reqd = (ll)__builtin_popcount(i);
    if(done != reqd) continue;
    mx = 0;
    dfs(nd, -1, 0);
    ans[mx]++;
  }
  for (ll i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}