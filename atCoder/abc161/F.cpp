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
ll k;
ll todo1(ll xx) {
	ll ct = 0;
	for(ll i = 2; i*i <= xx; i++) {
		if(xx%i == 0) {
			ll pp = xx;
			while(pp%i == 0) pp/=i;
			if(pp%i == 1) ct++;
			pp = xx;
			if(xx/i != i) {
				ll ii = xx/i;
				while(pp%ii == 0) pp/=ii;
				if(pp%ii == 1) ct++;
			}
		}
	}
	return ct;
}
ll todo2(ll xx){
	ll ct = 0;
	for(ll i = 2; i*i <= xx; i++) {
		if(xx%i == 0) {
			ct++;
			if(xx/i != i) ct++;
		}
	}
	return ct;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> k;
  if(k == 2) {
  	cout << 1 << endl;
  	return 0;
  }
  cout << todo1(k) + todo2(k-1) + 2 << endl;
  return 0;
} //good night.
