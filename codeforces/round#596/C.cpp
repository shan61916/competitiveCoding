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
ll n, p;
bool can(ll x) {
	ll todo = n - (p*x);
	if(todo <= 0) return false;
	if(x > todo) return false;
	return __builtin_popcountll(todo) <= x;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> p;
  for(ll i = 0; i < 1000; i++) {
  	if(can(i)) {
  		cout << i << endl;
  		return 0;
  	}
  }
  cout << -1 << endl;
  return 0;
} //good night.