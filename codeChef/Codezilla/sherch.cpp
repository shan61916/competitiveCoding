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
  vector<char> xx;
  string s;
  cin >> s;
  vector<ll> a(3000, 0);
  for(ll i = 0; i < n; i++) {
  	if(s[i] == '1') {
  		xx.pb('a');
  	} else if(s[i] == '2') {
  		xx.pb('b');
  		xx.pb('b');
  	} else if(s[i] == '3') {
  		xx.pb('a');
  		xx.pb('b');
  	} else if(s[i] == '4') {
  		a[0]+= 1;
  		ll zz = xx.size() ;
  		a[zz]-=1;
  	}
  }
  for(ll i = 1; i < 2500;  i++) {
     a[i]+=a[i-1];
  }
  for(ll i = 0; i < (ll)xx.size(); i++) {
  	if(a[i]%2 == 0) {
  		cout << xx[i];
  	} else {
  		if(xx[i] == 'a') cout << "b";
  		else cout << "a";
  	}
  }
  return 0;
} //good night.