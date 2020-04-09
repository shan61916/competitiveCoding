
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
	  ll T;
	  cin >> T;
	  while(T--) {
	   ll n, m;
	   cin >> n >> m;
	   char a[n][m]; 
	   for(ll i = 0; i < n; i++) {
	   	for(ll j = 0; j < m; j++) {
	   		if(i%2 == 1 and j%2 == 1) a[i][j] = 'B';
	   		else if(i%2 == 0 and j%2 == 0) a[i][j] = 'B';
	   		else a[i][j] = 'W';
	   	}
	   }
	   if(a[n-1][m-1] == 'B' and n%2 == 0 and m%2 == 1) a[n-1][m-1] = 'W';
	   else if(n%2 == 0 and m%2 == 0) a[n-1][0] = 'B';
	   else a[n-1][m-1] = 'B';
	   for(ll i = 0; i < n; i++) {
	   	for(ll j = 0; j < m; j++) cout << a[i][j];
	   	cout << endl;
	   }
	  }
	  return 0;
	} //good night.