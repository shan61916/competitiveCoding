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
  string s;
  cin >> s;
  ll n = s.length();
  vector<ll> a(n, 28); 
  ll mtill = s[0]-'a';
  for(ll i = 1; i < n; i++) {
     a[i] = mtill;
     mtill = min(mtill, (ll)(s[i]-'a'));
  }
  for(ll i = 0; i < n; i++) {
  	if(a[i] < s[i]-'a') {
  		cout << "Ann";
  	} else {
  		cout << "Mike";
  	}
  	cout << endl;
  }
  return 0;
} //good night.