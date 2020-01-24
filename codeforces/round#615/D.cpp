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
ll q, x;
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> q >> x;
  ll wanted = 0;
  unordered_map<ll, ll> key;
  while(q--) {
  	ll t;
  	cin >> t;
  	if(wanted%x == t%x) {
  		wanted++;
  		while(key[wanted%x] > 0) {key[wanted%x]--; wanted++;}
  		cout << wanted << endl;
  	} else {
  		key[t%x]++;
  		cout << wanted << endl;
  	} 
  }
  return 0;
} //good night.	
