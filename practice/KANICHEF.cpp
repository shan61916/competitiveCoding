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
bool cmp(pll a, pll b) {
	if(a.ff == b.ff) {
		return a.ss < b.ss;
	}
	return a.ff > b.ff;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, tot;
  cin >> n >> tot;
  set<pll, decltype(&cmp)> st(&cmp);
  for(ll i  = 1; i <= n; i++) {
      ll tp;
      cin >> tp;
      st.insert(mp(tp, i));
  }
  while(tot--) {
  	pll giv = *st.begin();
  	st.erase(st.begin());
  	cout << giv.ss << " ";
  	giv.ff--;
  	if(giv.ff > 0) st.insert(giv);
  }

  return 0;
} //good night.