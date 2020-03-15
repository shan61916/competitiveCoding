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
  vll a(n);
  map<ll, ll> ct; 
  set<ll> st;
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  	ct[a[i]]++;
  	st.insert(a[i]);
  }
  ll ans = 0;
  for(auto it: st) {
  	ans+= (ct[it] * (ct[it] - 1))/2;
  }
  ll prev = ans;
  for(ll i = 0; i < n; i++) {
  	ans-= (ct[a[i]] * (ct[a[i]] - 1))/2;
  	ct[a[i]]--;
  	ans+= (ct[a[i]] * (ct[a[i]] - 1))/2;
  	ct[a[i]]++;
  	cout << ans << endl;
  	// cout << " " << 	ans << endl;
  	ans = prev;
  }

  return 0;
} //good night.