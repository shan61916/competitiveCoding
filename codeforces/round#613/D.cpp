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
ll n;
vll arr[31][3];
ll currxor = 0;
ll find(ll bit, vll ar) {
	if(bit < 0) return 0;
	if(ar.size() == 0) return 0; 
	ll currans = 0;
  vll fir, sec;
  for(ll i = 0; i < (ll)ar.size(); i++) {
  	 if(ar[i]&(1ll<<bit))fir.pb(ar[i]);
  	 else sec.pb(ar[i]);
  } 
  if(fir.size() > 0 and sec.size() > 0)  currans = (1ll<<bit);
  ll ans1 = inf;
  if(fir.size() > 0)ans1 = find(bit-1, fir);
  if(sec.size() > 0)ans1 = min(ans1, find(bit-1, sec));
  currans+= ans1;
  return currans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  cout << find(31, a) << endl;
  return 0;
} //good night.