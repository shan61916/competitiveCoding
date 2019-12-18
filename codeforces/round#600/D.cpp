  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 

vll parent(200010, 0), sz(200010, 0), lrg(200010, 0), small(200010, 0);
void makeset(ll idx) {
  parent[idx] = idx;
  sz[idx] = 1;
  lrg[idx] = idx;
  small[idx] = idx;
}
ll findset(ll idx) {
  if(parent[idx] == idx) return idx;
  return parent[idx] = findset(parent[idx]);
}

void unio(ll a, ll b) {
  a = findset(a);
  b = findset(b);
  if(sz[a] < sz[b]) swap(a, b);
  lrg[a] = max(lrg[a], lrg[b]);
  small[a] = min(small[a], small[b]);
  sz[a]+= sz[b];
  parent[b] = a;
}

bool comp(ll x, ll y) {
  return small[x] < small[y];
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) makeset(i);
  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    if(findset(x) != findset(y))unio(x, y);
  }
  set<ll> givn;
  for(ll i = 1; i <= n; i++) {
    givn.insert(findset(i));
  }
  vll todo;
  for(auto it: givn) todo.pb(it);
  sort(all(todo), comp);
  ll ct = 0;
  for(ll i = 0; i < (ll)todo.size() - 1; i++) {
    ll xx = findset(todo[i]);
    ll yy = findset(todo[i+1]);
    if(lrg[xx] - small[xx] + 1 == sz[xx]) continue;
    unio(xx, yy);
    ct++;
  }
  cout << ct << endl;
  return 0;
} //good night.