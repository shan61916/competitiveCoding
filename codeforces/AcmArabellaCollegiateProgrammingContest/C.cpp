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
dll hypo(dll x, dll y) {
	dll ans = (dll)(x*x) + (dll)(y*y);
	return (dll)sqrt(ans);
}
dll perc(ll x, ll a) {
	dll pp = (dll)(x)/(dll)(100.0000);
	return (dll)((pp)*(dll)(a));
} 

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b, c, xe;
  cin >> a >> b >> c >> xe;
  dll ans = 0.00;
  ans+= hypo((dll)(a), (dll)(b + c));
  ans+= (dll)c;
  dll tot =(dll)perc((dll)(xe), hypo((dll)(b), (dll)(a)));
  ans+= tot;
  tot*=tot;
  dll y = tot/((dll)(a*a)/(dll)(b*b) + 1.00);
  dll x = tot-y;
  y = (dll)sqrt(y);
  x = (dll)(sqrt(x));
  x = (dll)(a - x);
  dll low = 0.00, high = x;
  ll eps = 150;
  auto dist = [&](dll p) {
  	dll d1 = hypo(y + c, (p - x));
  	dll d2 = hypo(pt, c);
  	return (d1 + d2);
  };
  while(eps--) {
  	ll p1 = (low) + (high - low)/3.00;
  	ll p2 = (high) - (high - low)/3.00;
  	dll a1 = dist(p1);
  	dll a2 = dist(p2);
  	if(a1 <= a2) {
  		high = p2;
  	} else {
  		low = p1;
  	}
  }
  return 0;
} //good night.