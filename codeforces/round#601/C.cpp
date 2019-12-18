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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  unordered_map<ll, ll> key;
  vector<vll> arr(n-2, vll(3, 0));
  for(ll i = 0; i < n-2; i++) {
    for(ll j = 0; j < 3; j++) cin >> arr[i][j];
    sort(all(arr[i]));
    for(auto it: arr[i]) key[it]++; 
  }   
  vector<vll> adj(n+1);
  ll idx = -1;
  ll dd = -1;
  for(ll i = 0; i < n-2; i++) {
    for(auto it: arr[i]) {
      adj[it].pb(i);
      if(idx == -1 and key[it] == 1) idx = it;
      else if(idx != -1 and key[it] == 1) dd = i; 
    }
  }
  for(auto it : arr[dd]) {
    key[it] = 3;
  }
  set<pll> st;
  vll ans;
  ll sz = 0;
  vector<ll> visited(n, false);
  vector<ll> done(n+1, false);
  st.insert(mp(1,idx));
  while(sz < n) {
    pll u = *st.begin();
    ll x = u.ss;
    key[x]--;
    done[x] = true;
    sz++;
    ans.pb(x);
    st.erase(st.begin());
    for(auto it: adj[x]) {
      if(!visited[it]) {
        for(auto et: arr[it]) {
          if(!done[et]) {
            st.erase(mp(key[et], et));
            key[et]--;
            st.insert(mp(key[et], et));
          }
        }
      }
    }
  }
  for(auto it: ans) cout << it << " ";
  return 0;
} //good night.