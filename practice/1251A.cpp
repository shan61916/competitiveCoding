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
  ll T;
  cin >> T;
  while(T--){
    string a; 
    cin >> a;
    string ans = "";
    vector<ll> vis(26, 0);
    ll n = a.length();
    for(ll i = 0; i < n; i++) {
    	ll ct = 0;
    	ll j = i;
    	char x = a[i];
    	while(j < n and a[j] == x) j++, ct++;
    	if(ct%2)  {
    		if(!vis[x-'a']) {
    		 ans+= x;
    		 vis[x-'a']++;
    		}
    	}
    	i = j-1;
    }
    sort(all(ans));
    cout << ans << endl;
  }
  return 0;
} //good night.