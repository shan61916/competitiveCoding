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
  vector<ll> a(n+1);
  ll ans = 1;
  for(ll i = 1; i <= n; i++) cin >> a[i];
  vector<vector<ll>> aux(n+1, vector<ll>(11, 0));
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= 10; j++) aux[i][j] = aux[i-1][j];
    aux[i][a[i]]++;
    set<ll> st;
    for(ll j = 1; j <= 10; j++) {
    	for(ll k = 1; k <= 10; k++) {
           if(j == k) st.insert(aux[i][k] -1);
           else st.insert(aux[i][k]);
    	}
    	st.erase(0);
    	// if(i == 13)cout << st.size() << endl;
    	if(st.size() <= 1) ans = i;
    	st.clear();
    }
  }
  cout << ans << endl;
  return 0;
} //good night.