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
	   ll n;
	   string s;
	   cin >> n;
	   cin >> s;
	   if(s[0] == '1' or s[n-1] == '1') {
	   	cout << n*2 << endl;
	   	continue;
	   }
	   ll tot = 0;
	   ll mx = 0;
	   ll done = 0;
	   for(ll i = 0; i < n; i++) if(s[i] == '1') tot++;
	   if(tot == 0) {
	   	cout << n << endl;
	   	continue;
	   }
	   for(ll i = 0; i < n; i++) {
	      if(s[i] == '1') {
	      	 done++;
	         mx = max(mx, (n - i)*2);
	         mx = max(mx, n + tot - done);
	      }
	   }
	   reverse(all(s)) ;
	   done = 0; 
	  for(ll i = 0; i < n; i++) {
	     if(s[i] == '1') {
	  	 done++;
	     mx = max(mx, (n - i)*2);
	     mx = max(mx, n + tot - done);
	   }
	  }
	   cout << mx << endl;
	  }
	  return 0;
	} //good night.