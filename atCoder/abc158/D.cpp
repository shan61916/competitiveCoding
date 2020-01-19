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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  string s;
  cin >> s;
  ll curr = 0;
  string front = "", back = "";
  ll q;
  cin >> q;
  while(q--) {
  	ll t;
  	cin >> t;
  	if(t == 1) curr^=1;
  	if(t == 2) {
  		ll f;
  	  cin >> f;
  	  char c;
  	  cin >> c;
  	  if(curr == 1) {
  	  	if(f == 1)back.pb(c);
  	  	else front.pb(c);
  	  } else {
  	  	if(f == 1) front.pb(c);
  	  	else back.pb(c);
  	  }
  	}
  }
  if(curr == 1) {
  	reverse(all(back));
  	reverse(all(s));
  	cout << back << s << front;
  }else {reverse(all(front)); cout << front << s << back << endl;}
  return 0;
} //good night.