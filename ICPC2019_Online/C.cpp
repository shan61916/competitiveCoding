//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    ll c = 0;
    vector<pair<pair<ll, ll>, ll>> vc(n);
    for (ll i = 0; i < n; i++) {
      cin >> vc[i].first.first >> vc[i].first.second >> vc[i].second;
      mp[vc[i].first.first] = mp[vc[i].first.second] = 0;
    }
    for (auto &i : mp) {
      i.second = c++;
    }
    multiset<ll> st[c+1];
    bool chk = true;
    for (ll i = 0; i < n; i++) {
      for (ll j = mp[vc[i].first.first]; j <= mp[vc[i].first.second]; j++) {
        st[j].insert(vc[i].second);
        if(st[j].count(vc[i].second) > 2) {
          chk = false;
          break;
        }
      }
    }
    if (chk) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
