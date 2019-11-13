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
vector<ll> arr(100010, 0);
vector<vll> segtree(400010, vll(26, 0)); 
vll combine(vll a, vll b) {
	 vll ans(26, 0);
	 for(ll i = 0; i < 26; i++) ans[i] = a[i] + b[i];
	 return ans;
}

void build(ll t, ll tl, ll tr) {
	if(tl == tr) {
		segtree[t][arr[tl]]++;
		return;
	}
	ll mid = (tl + tr)/2;
	build(2*t, tl, mid);
	build(2*t+1, mid+1, tr);
	segtree[t] = combine(segtree[2*t], segtree[2*t+1]);
	return ;
}
vll ret(26, 0);
vll query(ll t, ll tl, ll tr, ll l, ll r) {
	 if(l > r or tl > tr or l > tr or tl > r) return ret;
     if(tl >= l and tr <= r) {
	 	return segtree[t];
	 }
	 ll mid = (tl + tr)/2;
	 return combine(query(2*t, tl, mid, l, r), query(2*t+1, mid+1, tr, l, r));
}

void update(ll t, ll tl, ll tr, ll l, ll r, ll prev, ll ne) {
	 if(l > r or tl > tr or l > tr or tl > r) return ;
	 if(tl >= l and tr <= r) {
	 	segtree[t][prev]-=1;
	 	segtree[t][ne]+=1;
	 	return ;
	 }
	 ll mid = (tl + tr)/2;
     update(2*t, tl, mid, l, r, prev, ne);
     update(2*t+1, mid+1, tr, l, r, prev, ne);
     segtree[t] = combine(segtree[2*t], segtree[2*t+1]);
     return ;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  string s;
  cin >> s;
  ll n = s.length();
  for(ll i = 1; i <= n; i++) {
  	arr[i] = (ll)(s[i-1]-'a');
  }
  build(1, 1, n); 
  ll q;
  cin >> q;
  while(q--) {
  	ll x;
  	cin >> x;
  	if(x == 1) {
  		ll pt;
  		cin >> pt;
  		ll prev = arr[pt];
  		char nn ;
  		cin >> nn;
  		ll ne = nn -'a';
  		update(1, 1, n, pt, pt, prev, ne);
  		arr[pt] = ne;

  	} else if(x == 2) {
  		ll l, r;
  		cin >> l >> r;
  		vll ans = query(1, 1, n, l, r);
  		ll ct = 0;
  		for(ll i = 0; i < 26; i++) {
  			if(ans[i] > 0) ct++;
  		}
  		cout << ct << endl;
  	}
  }
  return 0;
} //good night.