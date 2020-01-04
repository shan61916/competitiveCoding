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
vll arr;
ll n;
ll a1, a2, ans = inf;
void divisors() {
	for(ll i = 1; i*i <= n; i++){
		if(n%i != 0) continue;
		ll x = i, y = n/i;
		ll lcm = (x*y)/(__gcd(x, y));
		if(lcm == n) {
			if(max(x, y) < ans) {
				ans = max(x, y);
				a1 = x;
				a2 = y;
			}
		}
	}
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  divisors();
  cout << a1 << " " << a2 << endl;
  return 0;
} //good night.