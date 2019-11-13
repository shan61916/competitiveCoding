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
const int MAX = 2e3 + 3;
const ll MOD = 1e15;
ll ncr[MAX][MAX];

void pascal() {
	for (int i = 0; i < MAX; ++i) {
		ncr[i][0] = ncr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
			if (ncr[i][j] >= MOD) ncr[i][j] -= MOD;
		}
	}
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  pascal();
  vll a(n);
  for(auto &x : a) cin >> x;
  sort(all(a)); 
  ll tot = ncr[n][3];
  // cout << tot << endl;
  for(ll i = 0; i < n-2; i++) {
  	 for(ll j = i+1; j < n-1; j++) {
       ll k = upper_bound(a.begin()+j+1, a.end(), a[i]+a[j]-1) - a.begin();
       if(k < n) tot-= (n-k);
  	 }
  }
  cout << tot << endl;
  return 0;
} //good night.