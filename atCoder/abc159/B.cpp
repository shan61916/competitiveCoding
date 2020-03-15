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
bool ispalin(string s) {
	ll n = s.length();
	for(ll i = 0; i < n/2; i++) {
		if(s[i] != s[n-1-i]) return false;
	}
	return true;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  string s;
  cin >> s;
  ll n = s.length();
  string a = s.substr(0, n/2);
  string b = s.substr(n/2 + 1, n/2);
  if(ispalin(a) and ispalin(b) and a == b) cout << "Yes";
  else cout << "No";
  return 0;
} //good night.