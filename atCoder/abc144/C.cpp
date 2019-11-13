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
ll div(ll n) {
	ll ans = (ll)(1e15);
	for(ll i = 1; i*i <= n; i++) {
		if(n%i == 0) {
			if(n%i == i) {
				ans = min(ans, i + i - 2);
			} else {
				ans = min(ans, i + (n/i) - 2);
			}
		}
	}
	return ans;
}
 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
 ll n;
 cin >> n;
 cout << div(n) << endl;
} //good night.