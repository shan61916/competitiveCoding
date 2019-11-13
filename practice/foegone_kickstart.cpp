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
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
  vector<char> check1(101, '0'), check2(101, '0');
  string s;
  cin >> s;
  reverse(all(s));
  for(ll i = 0; i < (ll)s.length(); i++) {
  	if(s[i] != '4') {
  		check1[i] = s[i];
  	} else {
  		check1[i] = '2';
  		check2[i] = '2';
  	}
  }

  string ans1 ="", ans2 = "";
  bool foo = true;
  for(ll i = 100; i >= 0; i--) {
  	if(foo and check1[i] == '0') continue;
  	else {
  		foo = false;
  		ans1+= check1[i];
  	}
  }
  // cout << ans2 << endl;
  foo = true;
    for(ll i = 100; i >= 0; i--) {
  	if(foo and check2[i] == '0') continue;
  	else {
  		foo = false;
  		ans2+= check2[i];
  	}
  }
   cout << ans1 << " " << ans2 << endl;
  }
  return 0;
} //good night.