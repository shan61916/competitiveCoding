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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll prev = 0;
  ll tot = (n*(n+1)/2) - n;
  char x = 'c';
  vector<ll> suff(n, 0), pref(n, 0);
  for(ll i = n-1; i >= 0; i--) {
  	if(s[i] == x) {
  		suff[i] = prev+1;
  	} else {
  		suff[i] = 1;
  	}
  	x = s[i];
  	prev = suff[i];
  }
  prev = 0;
  x = 'c';
  for(ll i = 0; i < n; i++) {
    if(s[i] == x) {
    	pref[i] = prev + 1;
    } else {
    	pref[i] = 1;
    }
    x = s[i];
    prev = pref[i];
  }
  for(ll i = 1; i < n; i++) {
  	 if(s[i] != s[i-1]) {
  	 	 tot-= (pref[i-1] + suff[i] - 1);
  	 }
  }
  cout << tot << endl;
  return 0;
} //good night.