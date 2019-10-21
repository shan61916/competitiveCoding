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

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    return true;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, p, w, d;
  cin >> n >> p >> w >> d;
  if(p == 0) {
  	cout << 0 << " " << 0 << " " << n << endl;
  	return 0;
  } 
  ll x, y, g;
  bool foo = find_any_solution(w, d, p, x, y, g);
  if(!foo) {
  	cout << -1;
  	return 0;
  }
  if(x < 0 and y < 0) {
  	cout << -1;
  	return 0;
  }
  if(x >=0 and y >= 0 and x + y <= n) {
  	cout << x << " " << y << " " << n - (x+y) << endl;
  	return 0;
  }
  for(ll i = -10000000; i < 10000000; i++) {
  	x+= d/g;
  	y-= w/g;
  	if(x >= 0 and y >= 0 and x + y <= n) {
  		cout << x << " " << y << " " << n - (x+y) << endl;
  		return 0;
  	}
  }
  cout << -1 << endl;
  return 0;
} //good night.	