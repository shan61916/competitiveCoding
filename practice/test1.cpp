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

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
  ll n;
  cin >> n;
  vector<pll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
  sort(all(a));
  vector<char> ans(n); 
  set<pll> st;
  bool foo = true;
  for(ll i = 0; i < n; i++) {
    while((*st.begin()).ff <= a[i].ff and st.size()) {
      st.erase(st.begin());
    }
    if(st.size() > 1) {
      foo = false;
      break;
    }
    if(st.size() == 1) {
      char ch = ans[(*st.begin()).ss];
      if(ch == 'J'){ st.insert(mp(a[i].ss, i)); ans[i] = 'C'; }
      else if (ch == 'C'){ st.insert(mp(a[i].ss, i)); ans[i] = 'J'; }
    } else {st.insert(mp(a[i].ss, i)); ans[i] = 'C';}
  }
  if(!foo) {
    cout << "IMPOSSIBLE" << endl;
    continue;
  }
  for(ll i = 0; i < n; i++) cout << ans[i];
  cout << endl;

  }
  return 0;
} //good night. 