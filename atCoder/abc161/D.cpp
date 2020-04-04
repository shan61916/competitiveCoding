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
  ll k;
  cin >> k;
  vector<string> lunlun;
  ll point_at = 0;
  for(ll i = 1; i <= 9; i++) {
  	string p = "";
  	p.pb(char(i + '0'));
  	lunlun.pb(p);
  }
  ll tot = 9;
  while(tot < k) {
  	string get = lunlun[point_at];
  	point_at++;
  	ll zz = get.back() - '0';
  	string res;
  	if(zz - 1 > -1) {
  		res = get + char(zz - 1 + '0');
  		lunlun.pb(res);
  		tot++;
  	}	
  	if(zz > -1 and zz < 10) {
  		res = get + char(zz + '0');
  		lunlun.pb(res);
  		tot++;
  	}
  	if(zz + 1 < 10) {
  		res = get + char(zz + 1 + '0');
  		lunlun.pb(res);
  		tot++;
  	}
  }
  // for(auto it: lunlun) cout << it << " ";
  cout << lunlun[k - 1] << endl;
  return 0;
} //good night.
