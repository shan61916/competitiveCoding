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

const ll MOD  = (ll)(1e9+7);
ll modmul(ll a, ll b) {
	return (a%MOD * b%MOD)%MOD;
}
ll fact[2000001] ;
void orial() {
	fact[0] = 1;
	fact[1] = 1;
	for(ll i = 2; i <= 1000010; i++) fact[i] = modmul(fact[i-1], i);
	for(ll i = 2; i <= 1000010; i++) fact[i] = modmul(fact[i], fact[i-1]);
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  orial();
  while(T--){
   ll n;
   cin >> n;
   cout << fact[n] << endl;
  }
  return 0;
} //good night.