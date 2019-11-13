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
bool comp(pll a, pll b)  {
	if(a.ff == b.ff) return a.ss < b.ss;
	return a.ff < b.ff;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   ll n;
   cin >> n;
   string s; 
   cin >> s;
   vector<pair<ll, ll>> a(n);
   for(ll i = 0; i < n; i++) {
   	 a[i].ff = s[i] - '0';
   	 a[i].ss = i;
   }
   sort(all(a), comp);
   bool foo = true;
   ll fmax = -1, fidx = -1, smax = -1, sidx = -1, smin = INT_MAX;
   vector<ll> ans(n, 0);
   for(ll i = 0; i < n; i++) {
   	  // cout << a[i].ff << " " << a[i].ss << " " << sidx << endl;
   	  if(a[i].ff >= fmax and a[i].ff <= smin and  a[i].ss > fidx) {
   	  	 ans[a[i].ss] = 1;
   	  	 fidx = a[i].ss;
   	  	 smax = max(smax, a[i].ff); 
   	  } else if(a[i].ff >= smax and a[i].ss > sidx) {
   	  	ans[a[i].ss] = 2;
   	  	sidx = a[i].ss;
   	  	// cout << a[i].ff << " " << a[i].ss << endl;
   	  	if(smin == INT_MAX) smin = a[i].ff;
   	  	smax = max(smax, a[i].ff) ;
   	  } else {
   	  	foo = false;
   	  	break;
   	  }
   }
   if(!foo) {
   	cout << "-" ;
   } else {
   	for(ll i = 0; i < n; i++) cout << ans[i];
   }
   cout << endl;
  }
  return 0;
} //good night.