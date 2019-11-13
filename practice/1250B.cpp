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
  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  ll ct = 0;
  for(ll i = 0; i < n; i++) {
  	if(s[i] == '1') {
       continue;
  	}
  	ct++;
  	ll j = i;
  	while(j < n and s[j] == '0')j++;
  	i = j-1;
  }
  if(ct == 0) {
  	cout << 0 << endl;
  	return 0;
  }
  if(a >= b) {
  	cout << ct*b << endl;
  	return 0;
  } else {
  	cout << (ct-1)*a + b << endl;
  }
  return 0;
} //good night.
