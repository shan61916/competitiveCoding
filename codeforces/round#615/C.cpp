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
ll a;
set<ll> st;
bool pre(ll x) {
	for(ll i = 2; i*i <= x; i++){
		if(x%i == 0) {
			a = i;
			if(st.count(a) == 0){return true;}
		}
	}
	return false;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--) {
   ll n;
   cin >> n;
   st.clear();
   bool xx = pre(n);
   if(xx){
   	st.insert(a);
   	n/=a;
   } else {
   	cout << "NO" << endl;
   	continue;
   }
   xx = pre(n);
   if(xx) {
   	st.insert(a);
   	n/=a;
   } else {
   	cout << "NO" << endl;
   	continue;
   }
   if(st.count(n) == 0) {
   	cout << "YES" << endl;
   	for(auto it: st) cout << it << " ";
   	cout << n << endl;
   } else {
   	cout << "NO"; 
   	cout << endl;
   }
  }
  return 0;
} //good night.