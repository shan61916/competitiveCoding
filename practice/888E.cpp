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
ll n, m;
vll a1, a2, s1, s2;
ll t1, t2; 
void recurse(ll idx, ll mask) {
	if(idx == t1) {
		ll tot = 0;
		for(ll i = 0; i < t1; i++) {
			if(mask&(1ll<<i)) tot = (tot%m + a1[i]%m)%m;
		} 
		s1.pb(tot);
		return ;
	}
	recurse(idx+1, mask);
	recurse(idx+1, mask|(1ll<<idx));
	return;
}
void recurse2(ll idx, ll mask) {
	if(idx == t2) {
		ll tot = 0;
		for(ll i = 0; i < t2; i++) {
			if(mask&(1ll<<i)) tot = (tot%m + a2[i]%m)%m;
		} 
		s2.pb(tot);
		return ;
	}
	recurse2(idx+1, mask);
	recurse2(idx+1, mask|(1ll<<idx));
	return;	
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> m;
  t1 = n/2; 
  t2 = n - t1;
  for(ll i = 0; i < n; i++) {
  	ll tp;
  	cin >> tp;
  	if(i < t1) a1.pb(tp);
  	else a2.pb(tp);
  }
  recurse(0, 0);
  recurse2(0, 0);
  sort(s2.begin(), s2.end()); 
  // for(auto it: s2) cout << it << " ";
  // cout << endl;
  ll mx = 0;
  for(auto it: s1) {
  	ll tf = (m) - (it);
    ll idx = 0;
    auto xx = lower_bound(all(s2), tf);
    if(xx == s2.end()) idx = s2.size() - 1;
    else {
        idx = xx - s2.begin();
        idx-=1;
    }
    ll ans = s2[idx];
  	mx = max(mx, (it + ans)%m); 
  }
  cout << mx << endl;
  return 0;
} //good night.