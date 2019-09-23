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

bool issqr(ll x) {
	ll tt = (ll)sqrt(x);
	return (tt*tt == x);
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  ll tt = n*n, p;
  for(ll i = 1; i <= min((ll)1e7, n-1); i++) {
      p = tt - (i*i);
      if(issqr(p)) {
      	cout << i << " " << (ll)sqrt(p) << endl;
      	return 0;
      }
  }
  return 0;
} //good night.