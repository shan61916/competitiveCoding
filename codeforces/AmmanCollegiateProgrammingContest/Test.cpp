//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

map<pair<ll, ll>, ll> mp;

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.clear();
    tout.clear();
    up.clear();
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}

vector<ll> lv;
vector<ll> ac, wa;

void dfs2(ll s, ll c1, ll c2, ll lvl, ll p) {
  lv[s] = lvl;
  ac[s] = c1;
  wa[s] = c2;
  for (auto i : adj[s]) {
    if (i != p) {
      dfs2(i, c1+mp[{s, i}], c2+mp[{i, s}], lvl+1, s);
    }
  }
}

int main() {
  IOS
  #ifdef SHAN
  freopen("input.txt", "r", stdin);
  #endif
  ll t;
  cin >> t;
  while (t--) {
    adj.clear();
    cin >> n;
    adj.resize(n);
    mp.clear();
    ll ans = 0;
    for (ll i = 0; i < n-1; i++) {
      ll a, b, c1, c2;
      cin >> a >> b >> c1 >> c2;
      ans += c1;
      ans += c2;
      a--, b--;
      adj[a].pb(b);
      adj[b].pb(a);
      mp[{a, b}] = c1;
      mp[{b, a}] = c2;
    }
    lv.clear();
    lv.resize(n);
    ac.clear();
    wa.clear();
    ac.resize(n);
    wa.resize(n);
    preprocess(0);
    dfs2(0, 0, 0, 0, -1);
    ll q;
    cin >> q;
    while (q--) {
      ll a, b;
      cin >> a >> b;
      a--, b--;
      ll lcaa = lca(a, b);
      ll a2 = 0;
      if (lv[b] > lv[lcaa]) {
        a2 += (wa[b]-wa[lcaa]);
      } else {
        a2 += (ac[b]-ac[lcaa]);
      }
      if (lv[lcaa] < lv[a]) {
        a2 += (ac[a]-ac[lcaa]);
      } else {
        a2 += (wa[a]-wa[lcaa]);
      }
      cout << ans-a2 << endl;
    }
  }
  return 0;
}