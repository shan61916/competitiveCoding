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
vector<vll> s2(18, vll()); 
vector<pll> s1;
ll n, k, a, b, n1, n2;
vll arr1, arr2;
vector<ll> spf(1000010, 0); 
const ll maxx = 1000010;
void smallest_prime_factor () {
  for(ll i = 2; i < maxx; i++) {
    spf[i] = i;
  }
  for(ll i = 4; i < maxx; i+=2) spf[i] = 2; // spf of an even number is 2.
  for(ll i = 3; i*i < maxx; i++) {
    if(spf[i] == i) {
      for(ll j = i*i; j < maxx; j+=i) {
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
}
ll goodness(ll x) {
  ll ct = 1;
  while(x!= 1) {
  	ll tt = spf[x];
    while(x%tt == 0) x/=tt;
    ct*=tt;
  }
  return ct; 
}
void recurse(ll idx, ll mask) {
	if(idx == n1) {
		ll prod = 0;
		for(ll i = 0; i < 20; i++) {
			if(mask&(1ll<<i)) prod+= goodness(arr1[i]);
		}
		ll tot = __builtin_popcountll(mask);
		s1.pb(mp(tot, prod));
		return ;
	}
	recurse(idx+1, mask);
	recurse(idx+1, mask|(1ll<<idx));
	return;
}
void recurse2(ll idx, ll mask) {
	if(idx == n2) {
		ll prod = 0;
		for(ll i = 0; i < 20; i++) {
			if(mask&(1ll<<i)) prod+= goodness(arr2[i]);
		}
		ll tot = __builtin_popcountll(mask);
		s2[tot].pb(prod);
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
  smallest_prime_factor();
  cin >> n >> k >> a >> b;
  n1 = n/2;
  n2 = n - n1;
  for(ll i = 0; i < n; i++) {
  	ll tp;
  	cin >> tp;
  	if(i < n1) arr1.pb(tp);
  	else arr2.pb(tp);
  }
  recurse(0, 0);
  recurse2(0, 0);
  for(ll i = 0; i <= n2; i++) {
  	sort(all(s2[i]));
  }
  ll ans = 0;
  for(auto it: s1) {
  	ll done = it.ff;
  	ll sdone = it.ss;
  	ll todo = k - done;
  	for(ll i = 0; i <= todo; i++) {
  	    auto it1 = lower_bound(all(s2[i]), sdone - a) - s2[i].begin();
  	    auto it2 = upper_bound(all(s2[i]), b - sdone) - s2[i].begin();
  	    ans+= (it2 - it1 + 1);
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.